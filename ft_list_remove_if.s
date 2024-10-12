global ft_list_remove_if
extern free

;void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
; NOTE: callee-saved regs:
; head               - rdi -> rbx
; data reference     - rsi -> r13
; compare function   - rdx -> r14
; data free function - rcx -> r15
; curr node          - r12
; NOTE: caller-saved regs:
; prev node          - r10
; next node          - r11

section .text
ft_list_remove_if:
	push rbp
	mov rbp, rsp
	push rbx
	push r12
	push r13
	push r14
	push r15
	test rdi, rdi
	jz exit
	test rdx, rdx
	jz exit
	test rcx, rcx
	jz exit
	mov rbx, rdi
	mov r12, [rdi]
	test r12, r12
	jz exit
	mov r13, rsi
	mov r14, rdx
	mov r15, rcx
	xor r10, r10
loop:
	lea r11, [r12 + 0x8]
	mov r11, [r11]
	mov rdi, [r12]
	mov rsi, r13
	call r14
	test rax, rax
	jz remove
	mov r10, r12
continue:
	test r11, r11
	jz exit
	mov r12, r11
	jmp loop
remove:
	test r10, r10
	jnz update_prev
	mov [rbx], r11
del:
	push r10
	push r11
	mov rdi, [r12]
	call r15
	mov rdi, r12
	call free
	pop r11
	pop r10
	jmp continue
update_prev:
	lea r8, [r10 + 0x8]
	mov [r8], r11
	jmp del
exit:
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	pop rbp
	ret
