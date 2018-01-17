global	_ft_memset

section .text

_ft_memset:
	push	rdi
	mov		rcx, rdx
	mov		rax, rsi
	cld
	rep		stosb ; stosb => rdi = al, rdi++, rep while rcx--
	pop		rax

done:
		ret
