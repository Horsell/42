#!/bin/zsh

set n;
l = ./sastantua 1 | tail -n 1 | wc -l

for $i in l
	./sastantua 1 | tail -n 1 | wc -m 
