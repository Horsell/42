#!/bin/zsh

ifconfig | grep eth | cut -d\  -f2
