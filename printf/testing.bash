#!/bin/bash
# для компиляции
make all
#clear
#gcc -o test main_test.c libftprintf.a components/libft/libft.a
gcc -o test main3.c libftprintf.a components/libft/libft.a
./test