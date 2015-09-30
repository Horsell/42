# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:53:00 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 14:31:12 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_strlen

_ft_strlen:
mov		rax, 0				; store '\0' to be cmp in repnz
not		rcx					; rcx = 0
mov		rcx, -1				; rcx = 2^32 - 1 or -1
cld							; clear DF flag
repnz	scasb				; repeat string operation : scan bytes, cmp al with (r)di
not		rcx					; (bitwise not) rcx = strlen + 1 (rcx was decremented by every repnz cmp)
lea 	rax, [rcx - 1]		; return value : address of rcx - 1
ret
