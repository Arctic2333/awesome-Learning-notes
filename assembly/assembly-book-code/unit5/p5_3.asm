assume cs:code
code segment 
	
	mov ax,0
	mov cx,123
	
	s:add ax,236
	loop s
	
	mov ax,4c00H
	int 21h
	
code ends
end