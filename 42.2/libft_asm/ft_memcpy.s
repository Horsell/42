# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 07:15:59 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 17:29:33 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_memcpy

_ft_memcpy:
push	rdi
mov		rcx, rdx		; arg3 (copy length) in arg4 (for rep)
cld						; clear DF flag
rep		movsb			; repeat copy of bytes
pop		rax				; clear rax(return void)
ret
