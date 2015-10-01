# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:09:28 by jpirsch           #+#    #+#              #
#    Updated: 2015/10/01 00:42:58 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_toupper

_ft_toupper:
mov		rax, rdi
cmp		rdi, 0x61		; cmp >= 'a'
jge		_check			; jump _check 
ret

_check:
cmp		rdi, 0x7a		; cmp <= 'z'
jle		_leave			; (apply toupper)
ret

_leave:
sub		rax, 32
ret
