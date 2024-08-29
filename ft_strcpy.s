global ft_strcpy

section .text
ft_strcpy:
	xor ecx, ecx
	dec rcx
loop:
	inc rcx
	mov BYTE al, [rsi + rcx]
	mov BYTE [rdi + rcx], al
	test al, al
	jnz loop
	mov rax, rdi
	ret
