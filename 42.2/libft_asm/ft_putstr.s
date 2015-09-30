# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putstr.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 03:49:55 by mbougrin          #+#    #+#              #
#    Updated: 2015/09/30 17:32:14 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern _write, _ft_strlen

section .text

global _ft_putstr

_ft_putstr:
mov		rsi, rdi		; copy str address to arg2 of write
call	_ft_strlen
mov		rdx, rax		; value of strlen in arg3 of write
mov		rdi, 1			; put stdout in arg1 of write
call	_write
