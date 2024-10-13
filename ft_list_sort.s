global ft_list_sort

;void ft_list_sort(t_list **begin_list, int (*cmp)());
; ascending order
section .text
ft_list_sort:
	push rbp
	mov rbp, rsp
	push rbx ; list head
	push r12 ; current node
	push r13 ; next node
	push r14 ; swap flag
	push r15 ; compare function
	test rsi, rsi
	jz exit
	test rdi, rdi
	jz exit
	mov rbx, [rdi]
	test rbx, rbx
	jz exit
	mov rbx, rdi
	mov r15, rsi
	xor r8, r8
	jmp loop
check:
	test r14, r14
	jz exit
	mov r8, r12
loop:
	mov r12, [rbx]
	xor r14, r14
bubble:
	lea r13, [r12 + 0x8]
	mov r13, [r13]
	cmp r13, r8
	jz check
	mov rdi, [r12]
	mov rsi, [r13]
	push r8
	call r15
	pop r8
	test eax, eax
	jns swap
	mov r12, r13
	jmp bubble
swap:
	mov rax, [r12]
	mov rcx, [r13]
	mov [r12], rcx
	mov [r13], rax
	inc r14
	mov r12, r13
	jmp bubble
exit:
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	pop rbp
	ret
