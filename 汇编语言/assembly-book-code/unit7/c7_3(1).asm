assume cs:codesg,ds:datasg

datasg segment
	db 'BaSiC'
	db 'MinIX'
datasg ends

codesg segment
	start:mov ax,datasg
	mov ds,ax
	mov bx,0
	
	mov cx,5
	s:
	and byte ptr 0[bx],11011111B
	or byte ptr 5[bx],00100000B
	inc bx
	loop s 
	
	mov ax,4c00h
	int 21h

codesg ends
end start