# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:08:19 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/01 08:25:28 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strcat

extern _ft_memcpy, _ft_strlen

section .text

_ft_strcat:
mov		rax, rdi			; arg1(dest string) to return register
push	rdi
jmp		_loop

_loop:
cmp		[rdi], byte 0x0		; check \0
je		_cpy
inc		rdi
jmp		_loop

_cpy:
push	rdi					; store (arg1 of strcat)
push	rsi					; store (arg2 of strcat)
mov		rdi, rsi			; for strlen of arg2
call	_ft_strlen
mov		rdx, rax			; for arg3(len) of memcpy
pop		rsi					; pop arg2 of strcat to memcpy
pop		rdi					; pop arg1 of strcat to memcpy
call	_ft_memcpy
pop		rax					; pop start of arg1(dest string of strcat)

_leave:
ret
