;**********************************************************************************************************
;* Name: test10.asm                                                                                       * 
;* Function: Causes the string "divide error" to be displayed in the middle of the screen when a division *
;*overflow occurs, and then returns DOS                                                                   *
;*                                                                                                        *
;* Return: no                                                                                             * 
;**********************************************************************************************************
assume cs:code

code segment
start:
	mov ax,cs  ;offset do0
	mov ds,ax
	mov si,offset do0
	
	mov ax,0  ;offset destination
	mov es,ax
	mov di,200h
	
	mov cx,offset do0end - offset do0  ;set transmission length
	cld  
	rep movsb
	
	mov ax,0  ;set interrupt vector
	mov es,ax
	mov word ptr es:[0*4],200h
	mov word ptr es:[0*4+2],0
	
	mov ax,4c00h
	int 21h
	
do0: 
	jmp short do0start  ;2 byte
	db "divide error!"  ;1 3byte  cs:0002 -> 0:202h
	
do0start:
	mov ax,cs  ;offset string
	mov ds,ax
	mov si,202h
	
	mov ax,0b800h  ;offset video memory
	mov es,ax
	mov di,12*160 + 36 * 2  ;offset display position
	
	mov cx,13  ;set cx = string's length
s:
	mov al,[si]
	mov es:[di],al
	inc si
	add di,2
	loop s
	
	mov ax,4c00h
	int 21h

do0end: nop
code ends
end start
	
	
	
	