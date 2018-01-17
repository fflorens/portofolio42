global	_ft_isdigit

section .text

_ft_isdigit:
		mov rax, 0
		cmp rdi, 48
		jl	done
		cmp rdi, 57
		jg	done
		mov rax, 1

done:
		ret
