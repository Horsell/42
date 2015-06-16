global	_ft_strlen

section .text

_ft_strlen:
xor		rcx, rcx
not		rcx
xor		al, al
cld
repne	scasb
not		rcx
dec		rcx
mov		rax, rcx
ret
