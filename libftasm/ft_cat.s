global _ft_cat

section .bss
buf:	 resb 0x80  ; buffer static de 0x80 = 128

section .text

_ft_cat:
	lea rsi, [rel buf]
	mov rdx, 0x80
	mov rax, 0x2000003 ;  read dans buff de 0x80 max
	syscall
	jc _end
	cmp rax, 0	; buff not empty
	jle _end
	push rdi ;sauvegarde fd
	mov rdi, 1
	mov rdx, rax
	mov rax, 0x2000004 ;  write sur fd=1 de rdx data depuis rsi
	syscall
	jc _end
	pop rdi ; restaure fd
	jmp _ft_cat

_end:
	ret
