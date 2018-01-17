global	_ft_memcpy

section .text

_ft_memcpy:
	push	rdi
	mov		rcx, rdx
	mov		rax, rsi
	cld
	rep		movsb ; stosb => rdi = al, rdi++, al++, rep while rcx--
	pop		rax

done:
	ret
