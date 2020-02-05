assume cs:code 

code segment
start:
	mov ax,4240h
	mov dx,000fh
	mov cx,0ah
	call divdw
	
	mov ax,4c00h
	int 21h
	
divdw:
	push ax
	
	mov ax,dx
	mov dx,0  ;Clear the DX of 16 bits higher than the divisor
	div cx  ;int(H / N)
	mov bx,ax  ;Temporary high int (H / N) quotient,Now DX is REM (H / N)
	
	pop ax
	div cx
	mov cx,dx
	mov dx,bx

	ret

code ends
end start