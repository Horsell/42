# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/01 06:37:32 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/01 06:45:03 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern _write

section	.bss

buff: resb 1024

section .text

global _ft_cat

_ft_cat:
mov		rdx, 1024			; buff size to arg3 of read
lea		rsi, [rel buff]		; addr of buf to arg2 of read
mov		rax, 0x2000003		; read address
syscall
jc		_leave				; as we use the raw syscall, we use the carry flag instead of rax
push	rdi					; store fd(arg1 of cat)
mov		rdi, 1				; stdout to arg1 of write
mov		rdx, rax			; nbr of bytes read returned to arg3 of write
call	_write
pop		rdi					; pop fd
cmp		rax, 0x0			; check nbr of byte written(if 0 ->end)
je		_leave
jmp		_ft_cat

_leave:
ret
