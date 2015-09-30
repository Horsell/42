# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 07:16:18 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 09:35:28 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern _write, _read

section	.bss

buff: resb 1024

section .text

_ft_cat:
mov		rdx, 1024
lea		rsi, [rel buff]
call	_read
cmp		rax, 0x0
jl		_leave
push	rdi
mov		rdi, 1
mov		rdx, rax
call	_write
pop		rdi
cmp		rax, 0x0
je		_leave
jmp		_ft_cat

_leave:
ret
