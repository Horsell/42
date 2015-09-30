# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 07:16:09 by jpirsch           #+#    #+#              #
#    Updated: 2015/09/30 17:28:26 by jpirsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global _ft_memset

_ft_memset:
push		rdi				; arg1 (data address) saved in stack (rsp)
mov		 	rcx, rdx		; arg3 (copy length) in arg4 (for rep)
mov			rax, rsi		; arg2 (value) in rax(for repeat copy)
cld							; clear DF flag
rep			stosb			; repeat copy to rdi(data address)
pop			rax				; clear rax(return void)
ret
