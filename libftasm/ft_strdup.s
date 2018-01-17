global _ft_strdup

extern _malloc, _ft_strlen, _ft_memcpy, _ft_bzero, _ft_strcat

section .text

_ft_strdup:
	push rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	call _malloc
	pop rsi
	mov rdi, rax
	push rdi
	call _ft_strcat
	pop rax
	ret
