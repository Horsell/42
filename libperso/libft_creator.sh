#!/bin/zsh

gcc -c *.c
gcc *.o
ar rc libstr.a *.o
rm *.o
