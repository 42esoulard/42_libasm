section .text
	global ft_strlen

ft_strlen:
	mov rax, 0 				; init counter
	jmp loop 				; go loop

loop:
	cmp byte [rdi + rax], 0 ; check \0
	jne increment			; not \0, i++
	jmp done 				; \0, go ret

increment:
	inc rax 				; i++
	jmp loop 				; go loop

done:
	ret 					; return
