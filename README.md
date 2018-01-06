[![Build Status](https://travis-ci.org/lightman1998/lab12.svg?branch=master)](https://travis-ci.org/lightman1998/lab12)
the demo application redirects data from stdin to a file **log.txt** using a package **print**.

## Задание:
Написать программу на *C++* обеспечивающую асинхронный запрос по заданному *URL* к *HTTPS* серверу на получение кода доступа. Для создания асинхронного запроса необходимо использовать следующие примитивы многопоточного программирования: `std::thread` для управления потоком и `std::promise` для асинхронной обработки кода ответа.
Передача аргумента происходит через командную строку.

## Terminal:
```ShellSession
$ ./main https://pornhub.com/
Redirect to: https://pornhub.com/
Код ответа: 200
```
