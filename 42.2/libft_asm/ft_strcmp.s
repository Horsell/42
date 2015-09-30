# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 07:16:33 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 14:30:25 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_strcmp

_ft_strcmp:
xor		eax, eax
xor		ecx, ecx
xor		rdx, rdx
push	rsi
push	rdi

_loop:
mov		cl, [rsi]
mov		al, [rdi]
cmp		cl, 0x0
jz		_ret
cmp		al, 0x0
jz		_ret
sub		ax, cx
jne		_leave
inc		rdi
inc		rsi
jmp		_loop

_leave:
pop		rdi
pop		rsi
cwde
cdqe
ret

_ret:
pop		rdi
pop		rsi
ret
