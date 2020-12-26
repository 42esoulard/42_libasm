section .text
	global ft_write

ft_write:
	mov rax, 1 			; syscall for write
	syscall 			; call write
	cmp rax, 0 			; check return value
	jl error 			; <0 = go ret error
	ret 				; else return rax

error:
	mov rax, -1 		; set ret value -1
	ret 				; return
