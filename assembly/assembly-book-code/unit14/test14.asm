assume cs:code

code segment
start:
	mov bx,0b800h
	mov es,bx

;--------------year	
	mov al,9
	out 70h,al
	in al,71h
	
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	
	add ah,30h
	add al,30h

	mov byte ptr es:[160*12+40*2],ah
	mov byte ptr es:[160*12+40*2+2],al
	mov byte ptr es:[160*12+40*2+4],'/'

;-------------------------------------month
	mov al,8
	out 70h,al
	in al,71h
	
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	
	add ah,30h
	add al,30h

	mov byte ptr es:[160*12+40*2+6],ah
	mov byte ptr es:[160*12+40*2+8],al
	mov byte ptr es:[160*12+40*2+10],'/'
	
;----------------------------------------day
	mov al,7
	out 70h,al
	in al,71h
	
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	
	add ah,30h
	add al,30h

	mov byte ptr es:[160*12+40*2+12],ah
	mov byte ptr es:[160*12+40*2+14],al
	mov byte ptr es:[160*12+40*2+16],' '	

;-----------------------------------------	hour
	mov al,4
	out 70h,al
	in al,71h
	
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	
	add ah,30h
	add al,30h

	mov byte ptr es:[160*12+40*2+18],ah
	mov byte ptr es:[160*12+40*2+20],al
	mov byte ptr es:[160*12+40*2+22],':'
	
;-----------------------------------------	min
	mov al,2
	out 70h,al
	in al,71h
	
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	
	add ah,30h
	add al,30h

	mov byte ptr es:[160*12+40*2+24],ah
	mov byte ptr es:[160*12+40*2+26],al
	mov byte ptr es:[160*12+40*2+28],':'
;-----------------------------------------	s 
	mov al,0
	out 70h,al
	in al,71h
	
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	
	add ah,30h
	add al,30h

	mov byte ptr es:[160*12+40*2+30],ah
	mov byte ptr es:[160*12+40*2+32],al

	mov ax,4c00h
	int 21h
code ends
end start