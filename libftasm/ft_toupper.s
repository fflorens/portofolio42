global	_ft_toupper

section .text

_ft_toupper:
		cmp rdi, 97
		jl	done
		cmp rdi, 122
		jg	done
		sub	rdi, 32

done:
		mov rax, rdi
		ret
