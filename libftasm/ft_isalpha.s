global	_ft_isalpha

section .text

_ft_isalpha:
		mov rax, 0
		cmp rdi, 65
		jl	_n
		cmp rdi, 90
		jg	_n
		mov rax, 1
		jmp done

_n:
		cmp rdi, 97
		jl	done
		cmp rdi, 122
		jg done
		mov rax, 1

done:
		ret
