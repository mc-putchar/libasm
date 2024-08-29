global ft_strcmp

section .text
ft_strcmp:
	xor ecx, ecx
	xor eax, eax
	xor edx, edx
	dec rcx
loop:
	inc rcx
	mov BYTE al, [rdi + rcx]
	mov BYTE dl, [rsi + rcx]
	sub eax, edx
	jnz done
	test dl, dl
	jnz loop
done:
	ret
