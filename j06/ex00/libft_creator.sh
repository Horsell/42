#!/bin/zsh

gcc -c *.c
ar r libstr.a *.o
rm *.o
