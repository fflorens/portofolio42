section .text

global _ft_strcat

_ft_strcat:
		push rdi

__goto_end_s1:
		cmp byte[rdi], 0
		je __cpy_bytes
		inc rdi
		jmp __goto_end_s1

__cpy_bytes:
		cmp byte[rsi], 0
		je end
		cld
		movsb ;rdi <- rsi, rsi++ rdi++
		jmp __cpy_bytes

end:
		movsb
		pop rax
		ret

