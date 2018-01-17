global	_ft_isalnum

section .text

_ft_isalnum:
		mov rax, 0
		cmp rdi, 65
		jl	__n
		cmp rdi, 90
		jg	__n
		mov rax, 1
		jmp done

__n:
		cmp rdi, 97
		jl	___n
		cmp rdi, 122
		jg ___n
		mov rax, 1
		jmp done

___n:
		cmp rdi, 48
		jl	done
		cmp rdi, 57
		jg done
		mov rax, 1

done:
		ret
