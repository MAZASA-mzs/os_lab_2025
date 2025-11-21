#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <getopt.h>

typedef struct {
    int start;
    int end;
    int mod;
} ThreadArgs;

// Inputs
int k = -1;
int pnum = -1;
int mod = -1;

unsigned long long global_result = 1;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void *factorial_worker(void *args) {
    ThreadArgs *t_args = (ThreadArgs *)args;
    unsigned long long local_result = 1;

    // Logic check: ensure start doesn't exceed end (handles edge cases)
    if (t_args->start <= t_args->end) {
        for (int i = t_args->start; i <= t_args->end; i++) {
            local_result = (local_result * (unsigned long long)i) % t_args->mod;
        }
    }

    // Update global result
    pthread_mutex_lock(&mut);
    global_result = (global_result * local_result) % t_args->mod;
    pthread_mutex_unlock(&mut);

    free(t_args);
    return NULL;
}

int main(int argc, char **argv) {
    static struct option options[] = {
        {"k", required_argument, 0, 'k'},
        {"pnum", required_argument, 0, 'p'},
        {"mod", required_argument, 0, 'm'},
        {0, 0, 0, 0}
    };

    int option_index = 0;
    int c;
    while ((c = getopt_long(argc, argv, "k:p:m:", options, &option_index)) != -1) {
        switch (c) {
            case 'k': k = atoi(optarg); break;
            case 'p': pnum = atoi(optarg); break;
            case 'm': mod = atoi(optarg); break;
            default: return 1;
        }
    }

    if (k < 0 || pnum <= 0 || mod <= 0) {
        fprintf(stderr, "Error: Invalid arguments.\n");
        fprintf(stderr, "Usage: %s -k <num >= 0> --pnum=<threads > 0> --mod=<mod > 0>\n", argv[0]);
        return 1;
    }
    
    if (k == 0) {
        printf("Factorial of 0 mod %d is: 1\n", mod);
        return 0;
    }

    if (pnum > k) {
        pnum = k;
    }

    pthread_t *threads = malloc(sizeof(pthread_t) * pnum);
    if (threads == NULL) {
        perror("Failed to allocate memory for threads");
        return 1;
    }

    int numbers_per_thread = k / pnum;
    int remainder = k % pnum;
    int current_start = 1;

    for (int i = 0; i < pnum; i++) {
        ThreadArgs *args = malloc(sizeof(ThreadArgs));
        if (args == NULL) {
            perror("Failed to allocate thread args");
            exit(1);
        }

        args->mod = mod;
        args->start = current_start;
        
        int range_size = numbers_per_thread + (i < remainder ? 1 : 0);
        args->end = current_start + range_size - 1;
        
        current_start += range_size;

        if (pthread_create(&threads[i], NULL, factorial_worker, (void *)args) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (int i = 0; i < pnum; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    printf("Factorial of %d mod %d is: %llu\n", k, mod, global_result);

    free(threads);
    return 0;
}