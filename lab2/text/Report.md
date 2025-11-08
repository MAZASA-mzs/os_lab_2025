# 1-2
Files edited, see changes there


Compile:
```bash
gcc ./lab2/src/$TASK_DIR/*[ch] -o ./lab2/src/$TASK_DIR/run
```

Chmod:
```bash
chmod +x ./lab2/src/$TASK_DIR/run
```

Run:
```bash
./lab2/src/$TASK_DIR/run
```

ENV:
1) `TASK_DIR = 'swap'`
2) `TASK_DIR = 'revert_string'`

# 3
Files from `swap` dir were compied to `libobs`
```bash
mkdir ./lab2/src/libobs
cp -r ./lab2/src/swap/ ./lab2/src/libobs/
```
Lib files were renamed to `libswap`, fixed `include`


## Static
Compile lib
```bash
gcc -c ./lab2/src/libobs/libswap.c -o ./lab2/src/libobs/libswap.o
```

Create lib archive
```bash
ar cr ./lab2/src/libobs/libswap.a ./lab2/src/libobs/libswap.o
```

Compile static linked executable
```bash
gcc ./lab2/src/libobs/main.c -L ./lab2/src/libobs/ -lswap -o ./lab2/src/libobs/run_static
```

## Dynamic
Compile lib
```bash
gcc -shared -fPIC -o ./lab2/src/libobs/libswap.so ./lab2/src/libobs/libswap.c
```

Compile dynamic linked executable
```bash
gcc -o ./lab2/src/libobs/run_dyn ./lab2/src/libobs/main.c -L./lab2/src/libobs -lswap
```

To run, specify lib path
```bash
export LD_LIBRARY_PATH=/home/mazasa/Code/Study/OS/os_lab_2025/lab2/src/libobs/:$LD_LIBRARY_PATH
./lab2/src/libobs/run_dyn
```