global	_ft_isascii

section .text

_ft_isascii:
		mov		rax, 0
		cmp		rdi, 0
		jnge	done
		cmp 	rdi, 127
		jnle	done
		mov		rax, 1

done:
		ret
