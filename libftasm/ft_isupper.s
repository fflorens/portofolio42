global	_ft_isupper

section .text

_ft_isupper:
		mov rax, 0
		cmp rdi, 65
		jl	done
		cmp rdi, 90
		jg	done
		mov rax, 1

done:
		ret
