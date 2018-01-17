
global	_ft_isprint

section .text

_ft_isprint:
		mov		rax, 0
		cmp		rdi, 32
		jnge	done
		cmp 	rdi, 126
		jnle	done
		mov		rax, 1

done:
		ret

