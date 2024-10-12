global ft_list_size

section .text
ft_list_size:
	push rbp
	mov rbp, rsp
	xor ecx, ecx
	mov rax, rdi
	test rax, rax
	jz exit
loop:
	inc rcx
	mov rax, [rax + 0x8]
	test rax, rax
	jnz loop
exit:
	mov rax, rcx
	pop rbp
	ret
