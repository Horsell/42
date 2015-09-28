
global _ft_bzero

section .text

_ft_bzero:
cmp		rsi, 0x0			; check rsi value == 0
je		_leave				; jump rsi == 0
mov		[rdi], byte 0x0		; mov rdi[] <- 0x0 == 0 ==  \0
dec		rsi					; decrementation rsi
inc		rdi					; incrementation rdi
jmp		_ft_bzero			; recursivite _ft_bzero

_leave:
ret							; return
