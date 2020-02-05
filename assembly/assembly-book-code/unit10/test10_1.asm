assume cs:code

data segment
	db 'Welcome to masm!',0
data ends

code segment
start: 
	mov dh,8  ; row
	mov dl,3  ;col
	
	mov cl,2  ;color
	
	mov ax,data
	mov ds,ax
	mov si,0  ;offset data
	
	call show_str
	
	mov ax,4c00h
	int 21h
	
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
	jcxz ok
	mov ch,al
	mov es:[bx+si],cx
	add si,2
	inc di
	jmp short show
	
ok: 
	pop si
	pop cx
	pop ax
	pop dx
	ret
	
	
code ends
end start