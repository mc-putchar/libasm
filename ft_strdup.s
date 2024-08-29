global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy
%define STACK_SIZE 0x10

section .text
ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, STACK_SIZE
	push rdi
	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc
	test rax, rax
	jz exit
	mov rdi, rax
	pop rsi
	call ft_strcpy
	jmp exit
exit:
	add rsp, STACK_SIZE
	pop rbp
	ret
