# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:09:08 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 14:28:28 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_isprint

_ft_isprint:
mov		rax, 1		; ret value
cmp		rdi, 0x20	; cmp  32 <
jl		_leave
cmp		rdi, 0x7e	; cmp 126 >
jg		_leave
ret

_leave:
mov		rax, 0		; ret value
ret
