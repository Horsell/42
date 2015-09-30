# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:08:28 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 14:25:37 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_isalpha

_ft_isalpha:
mov		rax, 1			; ret value
cmp		rdi, 0x41		; cmp 'A' <
jl		_leave
cmp		rdi, 0x5a		; cmp 'Z' >
jg		_next
ret

_next:
cmp		rdi, 0x61		; cmp 'a' <
jl		_leave
cmp		rdi, 0x7a		; cmp 'z' >
jg		_leave
ret

_leave:
mov		rax, 0			; ret value
ret
