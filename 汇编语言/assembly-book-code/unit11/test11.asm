assume cs:codesg

datasg segment
  db "Beginner's All-purpose Symbolic Instruction Code.",0
datasg ends

codesg segment
begin:
	mov ax,datasg
	mov ds,ax
	mov si,0  ;offset of datasg
	
	call letterc
	
	mov dh,8
	mov dl,3
	
	mov cl,2
	
	mov si,0
	
	call show_str
	
	mov ax,4c00h
	int 21h

letterc:
	pushf
	push si
	push cx
	
	mov ch,0
s:
	mov cl,ds:[si]  ;judge end of string
	jcxz ok
	cmp byte ptr ds:[si],61h  ;judge lower of letters
	jb continue
	cmp byte ptr ds:[si],7ah
	ja continue
	and byte ptr ds:[si],11011111b
continue:
	inc si
	jmp short s

ok:
	pop cx
	pop si
	popf
	ret
	
show_str:
	pushf
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
	popf
	ret

codesg ends
end begin 