# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:09:17 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 05:09:20 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

_ft_tolower:
mov		rax, rdi
cmp		rdi, 0x41		; cmp >= 'A'
jge		_check			; jump _check 
ret

_check:
cmp		rdi, 0x5a		; cmp <= 'Z'
jle		_leave			; (apply tolower)
ret

_leave:
add		rax, 32			; add 32
ret						; return 
