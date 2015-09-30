# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 07:16:09 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 09:35:26 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

_ft_memset:
push		rdi
mov		 	rcx, rdx
mov			rax, rsi
cld
rep			stosb
pop			rax
ret
