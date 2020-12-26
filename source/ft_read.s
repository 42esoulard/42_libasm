section .text
	global ft_read

ft_read:
	mov rax, 0		; syscall 0 = read
	syscall
	cmp rax, 0		; check read return
	jl error		; if neg, error
	ret 			; else return rax

error:
	mov rax, -1 	; set ret to -1
	ret