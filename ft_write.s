extern __errno_location
global ft_write
%define WRITE 1

section .text
ft_write:
	mov rax, WRITE
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
