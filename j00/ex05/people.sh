#!/bin/zsh

ldapsearch * -S apple-user | grep uid | sort -rf |cut -d , -f -1 | cut -c 9-
