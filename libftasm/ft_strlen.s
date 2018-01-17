global	_ft_strlen

section .text

_ft_strlen:
		xor rax,rax
		xor rcx,rcx
		not rcx
		repne scasb
		not rcx
		dec rcx
		mov rax, rcx
		ret

