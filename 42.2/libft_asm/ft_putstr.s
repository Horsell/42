# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putstr.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 03:49:55 by mbougrin          #+#    #+#              #
#    Updated: 2015/09/30 09:35:30 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_putstr

extern _write, _ft_strlen

section .text

_ft_putstr:
mov		rsi, rdi
call	_ft_strlen
mov		rdx, rax
mov		rdi, 1
call	_write
