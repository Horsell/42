# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 07:15:52 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 07:15:53 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern _malloc, _ft_strlen, _ft_memcpy

section .text

_ft_strdup:
push	rdi
call	_ft_strlen
mov		rdi, rax
push	rdi
call	_malloc
pop		rdx
pop		rsi
mov		rdi, rax
call	_ft_memcpy
ret
