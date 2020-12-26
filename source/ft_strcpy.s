section .text
	global ft_strcpy

ft_strcpy:
	mov rcx, 0 					; init counter
	jmp loop 					; if source or dest, go loop

loop:
	mov al, byte [rsi + rcx] 	; stock s1 elem
	mov byte [rdi + rcx], al 	; stock to dest
	cmp al, 0 					; check \0
	jne increment 				; not \0, go increment
	jmp done 					; \0 go ret

increment:
	inc rcx 					; increment counter
	jmp loop					; back to loop

done:
	mov rax, rdi 				; set ret as dest str
	ret 						; ret rax
