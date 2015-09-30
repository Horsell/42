# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:08:19 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 17:34:33 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_strcat

_ft_strcat:
mov		rax, rdi			; arg1(dest string) to return register
jmp		_loop

_loop:
cmp		[rdi], byte 0x0		; check \0
je		_loop_cpy
inc		rdi
jmp		_loop

_loop_cpy:
movsq						; copy rsi(src) -> rdi(dst)
cmp		[rsi], byte 0x0		; check \0
je		_leave
inc		rdi
inc		rsi
jmp		_loop_cpy

_leave:
ret
