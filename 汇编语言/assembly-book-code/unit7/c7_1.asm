assume cs:code,ds:data

data segment
	db 'unIX'
	db 'foRK'
data ends

code segment
	start:mov al,'a'
	mov bl,'b'
	
	mov ax,4c00H
	int 21H
code ends
end start