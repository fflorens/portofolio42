global	_ft_puts

section .data
null:
	.string db "(null)", 10
	.len equ $-null.string
endl:
	.string db 10
	.len equ $-endl.string

section .text

_ft_puts:
		cmp rdi, 0
		je _ft_puts_null
		cmp byte[rdi], 0
		je _ft_puts_endl
		mov rsi, rdi
		mov rdx, 0

__ft_puts:
		inc rdi
		inc rdx
		cmp byte[rdi], 0
		jne	__ft_puts

_ft_puts_put:
		mov		rdi, 1
		mov		rax, 0x2000004 ; write
		syscall

_ft_puts_endl:
		mov		rdi, 1
		lea		rsi, [rel endl.string]
		mov		rdx, endl.len
		mov		rax, 0x2000004 ; write
		syscall
		ret

_ft_puts_null:
		mov		rdi, 1
		lea		rsi, [rel null.string]
		mov		rdx, null.len
		mov		rax, 0x2000004 ; write
		syscall
		ret

