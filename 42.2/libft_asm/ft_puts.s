# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:04:07 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/01 08:34:40 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_puts

_ft_puts:
cmp		rdi, 0x0
je		_ret	
mov		rsi, rdi

_write_char:
cmp		[rsi], byte 0x0		; check \0
je		_leave
mov     rax, 0x2000004 		; write
mov     rdi, 1 				; init rdi stdout
mov     rdx, 1				; len write
syscall						; call write
inc		rsi					; incremente rsi
jmp		_write_char			; jump _write_char

_leave:

push	0x0A				; push on the stack \n
mov		rsi, rsp			; assign rsi <- rsp
mov     rax, 0x2000004 		; write
mov     rdi, 1 				; stdout
mov     rdx, 1				; len write
syscall						; call write

pop		rsi					; pop \n on the stack
mov     rax, 0x0A			; ret value
mov		rdi,0				; init rdi stdin
ret							; return

_ret:
ret
