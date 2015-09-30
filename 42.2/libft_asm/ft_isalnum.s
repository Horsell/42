# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 05:08:40 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 05:08:43 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

_ft_isalnum:
mov		rax, 1			; ret value
cmp		rdi, 0x30		; cmp '0' <
jl		_leave
cmp		rdi, 0x39		; cmp '9' >
jg		_next
ret

_next:
cmp		rdi, 0x41		; cmp 'A' <
jl		_leave
cmp		rdi, 0x5a		; cmp 'Z' >
jg		_next_cmp
ret

_next_cmp:
cmp		rdi, 0x61		; cmp 'a' <
jl		_leave
cmp		rdi, 0x7b		; cmp 'z' >
jg		_leave
ret

_leave:
mov		rax, 0			; ret value
ret
