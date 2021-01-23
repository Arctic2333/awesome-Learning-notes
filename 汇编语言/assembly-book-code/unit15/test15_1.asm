assume cs:code 

stack segment
	db 128 dup (0)
stack ends

data segment 
	dw 0,0
data ends

code segment
start:mov ax,stack
	mov ss,ax
	mov sp,128
	
	mov ax,data
	mov ds,ax
	
	mov ax,0
	mov es,ax
	
	push es:[9*4]
	pop ds:[0]
	push es:[9*4+2]
	pop ds:[2]  ;将原来int 9 的入口放在ds：0 ds:2单元中
	
	cli
	mov word ptr es:[9*4],offset int9
	mov es:[9*4+2],cs
	sti
	
	mov ax,0b800h
	mov es,ax
	mov ah,'a'
s:	mov es:[160*12+40*2],ah
	call delay
	inc ah
	cmp ah,'z'
	jna s
	
	mov ax,0
	mov es,ax
	
	push ds:[0]
	pop es:[9*4]
	push ds:[2]
	pop es:[9*4+2]  ;恢复到原来的地址
	
	mov ax,4c00h
	int 21h
	
delay:push ax
	push dx
	mov dx,100h
	mov ax,0
s1: sub ax,1
	sbb dx,0
	cmp ax,0
	jne s1
	cmp dx,0
	jne s1
	pop dx
	pop ax
	ret
	
int9: push ax
	push bx
	push es
	
	in al,60h
	
	pushf
	call word ptr ds:[0]
	
	cmp al,1
	jne int9ret
	
	mov ax,0b800h
	mov es,ax
	inc byte ptr es:[160*12+40*2]
	
int9ret:pop es
	pop bx
	pop ax
	iret

code ends
end start	