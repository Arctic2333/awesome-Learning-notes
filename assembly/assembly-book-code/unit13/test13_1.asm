assume cs:code

code segment 
start:	mov ax,cs
	mov ds,ax
	mov si,offset i_start
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset i_end - offset i_start
	cld
	rep movsb
	
	mov ax,0
	mov es,ax
	mov word ptr es:[7ch*4],200h
	mov word ptr es:[7ch*4+2],0
	
	mov ax,4c00h
	int 21h
	
i_start:
	mov ax,0B800h
	mov es,ax
	

	mov al,160
	mul dh
	mov di,ax
	
	mov al,2
	mul dl
	add di,ax
	
s:	mov al,ds:[si]
	cmp al,0
	je ok
	mov ah,cl
	mov es:[di],ax
	inc si
	add di,2
	jmp s
	
ok: iret

i_end:nop

code ends
end start