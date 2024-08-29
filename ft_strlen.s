global ft_strlen

section .text
ft_strlen:
	xor eax, eax
	dec rax
loop:
	inc rax
	cmp byte [rdi + rax], 0
	jnz loop
	ret
