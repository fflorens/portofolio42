global	_ft_bzero

section .text

_ft_bzero:
		cmp rsi, 0
		je done
		mov byte[rdi], 0
		inc rdi
		dec rsi
		jmp _ft_bzero

done:
		ret
