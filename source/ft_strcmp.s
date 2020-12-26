section .text
	global ft_strcmp

ft_strcmp:
	mov rcx, 0 					; init counter
	jmp loop 					; go loop

loop:
	mov al, byte [rsi + rcx] 	; stock elem from s1
	mov bl, byte [rdi + rcx]	; stock elem from s2
	cmp al, 0					; check if s1 is over
	je format					; if yes, go format and ret
	cmp bl, 0					; check if s2 is over
	je format					; if yes, go format and ret
	cmp al, bl 					; compare s1 and s2
	je increment 				; if == move to next elem
	jmp format 					; else go fix return value

increment:
	inc rcx 					; increment counter
	jmp loop 					; back to loop

error:
	mov rax, -1 				; set return value to -1
	ret

format:
	sub bl, al 					; diff btw s1 and s2
	cmp bl, 0					; check diff sign
	jg ret_sup					; if > 0 : set ret to 1
	jl ret_inf					; if < 0 : set ret to -1
	mov rax, 0					; else set ret 0
	jmp done

ret_sup:
	mov rax, 1
	jmp done

ret_inf:
	mov rax, -1

done:
	ret 
