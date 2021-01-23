;**********************************************************************************************************
;* Name: dtoc    test for curriculum design                                                               * 
;* Function: convert DWORD type data to a string representing decimal system, and the string ends with 0. *
;* Parameter: (AX) = lower 16 bits of DWORD data                                                          *
;* (DX) = DWORD data high 16 bits                                                                         *
;* Ds: Si refers to the first address of the string                                                       *
;* Return: no                                                                                             * 
;**********************************************************************************************************
assume cs:code

data segment
	dd 345980
len dw 0
data ends

re segment
	db 10 dup (0)
re ends

code segment
start:
	mov ax,data
	mov es,ax
	mov bx,0  ;offset data
	
	mov ax,re
	mov ds,ax
	mov si,0  ;offset re
	
	mov ax,es:[bx]
	mov dx,es:[bx+2]
	
	call dtoc
	
	mov dh,8  ; row
	mov dl,3  ;col
	
	mov cl,2  ;color
	
	mov si,0
	
	call show_str
	
	mov ax,4c00h
	int 21h
	
dtoc:   ;pop 和 push 不匹配 导致ret不能正常返回 call的下一句，数据计算也不对,翻转 1.寄存器存长度+栈 2.寄存器存长度+两个‘指针’头尾兑换
	push dx
	push bx
	push cx
	push si
	push ds
	push es
	
	
change:
	push ax   ;让里面的push ax 和pop 配对 不打乱外层push
	mov cx,0ah
	mov ax,dx
	mov dx,0
	div cx
	mov bx,ax
	
	pop ax
	div cx
	mov ds:[si],dl  ;remainder
	add byte ptr ds:[si],30h
	mov dx,bx
	inc si
	inc word ptr es:len[0]
	
	cmp dx,0
	jne change
	cmp ax,0  ;judge if the quotient is 0
	jne  change
	
transposition:
	mov ax,es:len[0]
	mov bl,2
	div bl
	mov cl,al
	dec si
	mov di,0
	s:
		mov al,ds:[di]
		mov bl,ds:[si]
		mov ds:[di],bl
		mov ds:[si],al
		dec si
		inc di
		loop s 
	
ok:	
	pop es
	pop ds
	pop si
	pop cx
	pop bx
	pop dx
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
	jcxz ok2
	mov ch,al
	mov es:[bx+si],cx
	add si,2
	inc di
	jmp short show
	
ok2: 
	pop si
	pop cx
	pop ax
	pop dx
	ret	
	
code ends
end start