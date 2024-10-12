global ft_list_push_front

section .text
ft_list_push_front:
	push rbp
	mov rbp, rsp
	test rdi, rdi
	jz exit
	test rsi, rsi
	jz exit
	mov rax, [rdi]
	mov [rsi + 0x8], rax
	mov [rdi], rsi
exit:
	pop rbp
	ret
