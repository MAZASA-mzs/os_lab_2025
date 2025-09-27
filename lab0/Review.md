Задание 2:
- в проекте lab0 создать папку hello
  `cd os_lab_2025/lab0 && mkdir hello`
- внутри этой папки создать пустой файл empty
  `touch hello/empty`
- скопировать файл hello.c из lab0/src в новую папку
  `cp ./src/hello.c ./hello/`
- переименовать его в newhello.c
  `mv ./hello/hello.c ./hello/newhello.c`

# Задание 3
`gcc hello/newhello.c -o hello_world && ./hello_world`
