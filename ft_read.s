extern __errno_location
global ft_read
%define READ 0

section .text
ft_read:
	mov rax, READ
	syscall
	cmp rax, 0
	js err
	ret
err:
	neg rax
	mov r8, rax
	call __errno_location
	mov [rax], r8
	mov rax, -1
	ret
