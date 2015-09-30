# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:09:43 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 05:13:17 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

_ft_bzero:
cmp		rsi, 0x0			; end of copy ? (rsi : length arg)
je		_leave
mov		[rdi], byte 0x0		; mov rdi[] <- 0x0 == 0 ==  \0
dec		rsi
inc		rdi
jmp		_ft_bzero			; recursivite _ft_bzero

_leave:
ret
