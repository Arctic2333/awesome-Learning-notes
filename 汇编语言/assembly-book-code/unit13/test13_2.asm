assume cs:code

code segment
start:  mov ax, cs
        mov ds, ax
        mov si, offset show
        mov ax, 0
        mov es, ax
        mov di, 200h
        mov cx, offset showend-offset show
        cld
        rep movsb

        mov ax, 0
        mov es, ax
        mov word ptr es:[7ch*4], 200h
        mov word ptr es:[7ch*4+2], 0

        mov ax, 4c00h
        int 21h

show:   push bp
        mov bp, sp
        dec cx
        jcxz showret
        add [bp+2], bx
showret:pop bp
        iret
showend:nop

code ends
end start
