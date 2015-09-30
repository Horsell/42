# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:08:50 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 14:28:14 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_isdigit

_ft_isdigit:
mov		rax, 1			; ret value
cmp		rdi, 0x30		; cmp '0' <
jl		_leave
cmp		rdi, 0x39		; cmp '9' >
jg		_leave
ret

_leave:
mov		rax, 0			; ret value
ret
