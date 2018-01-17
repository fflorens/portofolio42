global	_ft_islower

section .text

_ft_islower:
		mov rax, 0
		cmp rdi, 97
		jl	done
		cmp rdi, 122
		jg done
		mov rax, 1

done:
		ret
