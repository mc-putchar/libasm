global ft_atoi_base

; int ft_atoi_base(char *str, char *base);
section .text
ft_atoi_base:
	push rbp
	mov rbp, rsp
	push rbx
	xor eax, eax
	xor ebx, ebx
	xor ecx, ecx
	test rdi, rdi
	jz exit
	test rsi, rsi
	jz exit
	mov r10, 0x1 ; negative flag

check_base:
	mov BYTE bl, [rsi + rcx]
	test bl, bl
	jz prefix_check
	test bl, 0x2b ; '+'
	je bad
	test bl, 0x2d ; '-'
	je bad
	mov BYTE r8b, bl
	call isspace
	test rax, rax
	jz dups
bad:
	xor rax, rax
	jmp exit

dups:
	mov rdx, rcx
duploop:
	inc rdx
	mov BYTE r8b, [rsi + rdx]
	cmp bl, r8b
	je bad
	test r8b, r8b
	jnz duploop
	inc rcx
	jmp check_base

isspace:
	xor rax, rax
	cmp r8b, 0x20 ; ' '
	je aye
	cmp r8b, 0xd ; whitespaces upper bound
	jg nay
	cmp r8b, 0x9 ; whitespaces lower bound
	jl nay
aye:
	inc rax
nay:
	ret

prefix_check:
	cmp rcx, 0x2
	jl bad
	xor rdx, rdx
preloop:
	mov BYTE r8b, [rdi + rdx]
	test r8b, r8b
	jz end
	call isspace
	test rax, rax
	jz sign
	inc rdx
	jmp preloop

sign:
	cmp r8b, 0x2b
	je plus
	cmp r8b, 0x2d
	jne convert
	neg r10
plus:
	inc rdx
	mov BYTE r8b, [rdi + rdx]
	jmp sign

base_value:
	xor r9, r9
bvloop:
	mov BYTE bl, [rsi + r9]
	cmp bl, dl
	je found
	inc r9
	test bl, bl
	jnz bvloop
found:
	ret

convert:
	xor rax, rax
	mov r8, rdx
conloop:
	mov BYTE dl, [rdi + r8]
	test dl, dl
	jz end
	call base_value
	cmp r9, rcx
	jge end
	imul rax, rcx
	add rax, r9
	inc r8
	jmp conloop

end:
	test rax, rax
	jz exit
	imul rax, r10
exit:
	pop rbx
	pop rbp
	ret
