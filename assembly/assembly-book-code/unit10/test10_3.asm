assume cs:code,ds:data

data segment
	db 10 dup (0)
data ends

code segment
start:
	mov ax,12666
	mov bx,data
	mov ds,bx
	mov si,0
	call dtoc
	
	mov dh,8
	mov dl,3
	
	mov cl,2
	
	mov si,0
	
	call show_str
	
	mov ax,4c00h
	int 21h

dtoc:
	push ax
	push si
	push bx
	push cx
	push di
	
	mov bx,10
	mov di,si
	mov cx,0
otc:
	push cx
	mov cx,ax
	jcxz transposition
	pop cx
	mov dx,0
	div bx
	mov ds:[di],dl
	add byte ptr ds:[di],30h
	inc di
	inc cx
	jmp short otc
	
transposition:
	pop cx
	mov byte ptr [di],0
	dec di
	mov ax,cx
	mov bl,2
	div bl
	mov cl,al
	s:
		mov al,ds:[di]
		mov bl,ds:[si]
		mov ds:[di],bl
		mov ds:[si],al
		inc si
		dec di
		loop s 

ok:
	pop di
	pop cx
	pop bx
	pop si
	pop ax
	ret
	
show_str:
	push dx
	push ax
	push cx
	push si
	
	mov ax,0B800h  ;begin
	mov es,ax
	
	mov al,0a0h
	dec dh
	mul dh
	mov bx,ax
	
	mov al,2
	dec dl
	mul dl
	add bx,ax
	
	mov di,0
	mov si,0
	
	mov al,cl  ;save color
	
show:
	mov ch,0
	mov cl,ds:[di]
	jcxz ok_2
	mov ch,al
	mov es:[bx+si],cx
	add si,2
	inc di
	jmp short show
	
ok_2: 
	pop si
	pop cx
	pop ax
	pop dx
	ret
	
code ends
end start