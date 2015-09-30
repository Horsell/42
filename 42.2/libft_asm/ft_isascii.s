# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:09:00 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 05:09:02 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

_ft_isascii:
mov		rax, 1		; ret value
cmp		rdi, 0x00 	; cmp 0 <
jl		_leave
cmp		rdi, 0x7f	; cmp > 127
jg		_leave
ret

_leave:
mov		rax, 0		; ret value
ret
