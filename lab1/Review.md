# Задание 1
- Запустите скрипт background.sh в фоновом режиме.
    `cd os_lab_2025/lab1 && source src/background.sh &`
- Создайте текстовый файл и выведите его содержимое на экран терминала.
    `touch text.txt && cat text.txt`
- Очистите окно терминала.
    `clear`
- Посчитайте количество символов в файле.
    `cat text.txt | wc -m`

# Задание 2
С помощью команды grep, используя pipe и редирект (>), запишите в файл with_cake.txt все строчки из файла cake_rhymes.txt, в которых есть слово cake.
    `cat src/cake_rhymes.txt | grep -i "cake" > with_cake.txt`

Сделайте команду rm "тихой", используя редирект в `/dev/null`
    `rm text.txt > /dev/null 2>&1`

# Задание 3
Сделайте файл hello.sh исполняемым, выполните его.
    `chmod +x src/hello.sh && src/hello.sh`
Напишите bash скрипт, который выводит текущий путь, текущую дату и время, а также содержимое переменной окружения PATH.
    ```cat << EOF > script.sh
#!/bin/bash
pwd
date
echo "\$PATH"
EOF
    ```

# Задание 4
- Напишите скрипт average.sh, который выводит количество и среднее арифмитическое его входных аргументов. Скрипт должен работать с аргументами, а не читать числа из стандартного потока ввода или другого источника.
    ```
cat << EOF > average.sh
#!/bin/bash

if [ \$# -eq 0 ]; then
    echo "Нет входных аргументов."
    exit 1
fi

SUM=0
CNT=\$#

for ARG in "\$@"; do
    SUM=\$(echo "\$SUM + \$ARG" | bc)
done

AVG=\$(echo "scale=2; \$SUM / \$CNT" | bc)

echo "Num of args: \$CNT"
echo "Average: \$AVG"
EOF
```
- Используя od и dev/random создайте файл numbers.txt из 150 рандомных чисел.
    `od -An  -N "$(echo 150*4 | bc)" -w4 -i /dev/random  > numbers.txt`
- "Скормите" скрипту average.sh значения из файла numbers.txt.
    `cat numbers.txt | xargs ./average.sh
`