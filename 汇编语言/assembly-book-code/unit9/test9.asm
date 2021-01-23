assume cs:codesg,ds:datasg,ss:stacksg

datasg segment
	db 'welcome to masm!'
	db 02h,24h,71h
datasg ends

stacksg segment
	dw 0,0,0,0
stacksg ends

codesg segment

	start:mov ax,datasg  ;offset datasg
	mov ds,ax
	mov bx,0
	mov si,0
	mov bp,10h
	
	mov ax,stacksg
	mov ss,ax  ;init stack 
	mov sp,8
	
	mov ax,0B800h  ;offset aim
	mov es,ax
	mov di,720h
	
	mov cx,3
	s:
		push cx
		mov cx,16
		mov ax,0
		mov bx,0
	
			s0:
			mov al,[bx]
			mov ah,ds:[si+bp]
			mov word ptr es:[di],ax
			inc bx
			add di,2
			loop s0
	
		pop cx
		add di,80h
		inc si
	loop s 
	
	all:
	jmp short all
	
	mov ax,4c00h
	int 21h

codesg ends
end start