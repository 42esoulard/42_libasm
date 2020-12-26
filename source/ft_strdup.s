section .text
	global ft_strdup
	extern ft_strlen			; include ft_strlen
	extern malloc				; include malloc
	extern ft_strcpy			; include ft_strcpy

ft_strdup:
	push rdi					; put param on top of stack pile
	call ft_strlen				; ft_strlen of rdi (s1)
	add rax, 1					; len++ for \0
	mov rdi, rax				; move len to rax to send malloc 
	call malloc wrt ..plt		; malloc len AND relocate to align on stack
	cmp rax, 0 					; check malloc ret	
	je error					; if ret == null, jmp error
	pop rsi						; get back strdup param in rsi
	mov rdi, rax				; get mallocd string in rdi
	call ft_strcpy				; ft_strcpy(rdi, rsi)
	ret 						; return rax from ft_strcpy

error:
	pop rdi						; take pushed param off top
	mov rax, 0 					; null ret
	ret 						; ret