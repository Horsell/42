# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 07:15:52 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/01 06:01:06 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern _malloc, _ft_strlen, _ft_memcpy

section .text

global _ft_strdup

_ft_strdup:
mov		r15, rdi	; store string addr
call	_ft_strlen
mov		rdi, rax    ; size to arg of malloc
push	rdi			; store string size
call	_malloc
pop		rdx			; string size to arg3 of memcpy
mov		rsi, r15	; string addr to arg2 of memcpy
mov		rdi, rax	; malloc addr to arg1 of memcpy
call	_ft_memcpy
ret
