# unit 10

call 和 ret 指令都是转移指令，它们修改IP，或同时修改CS和IP。

## ret 和 retf

**ret指令用栈中的数据，修改IP的内容，实现近转移**

**retf指令用栈中的数据，修改CS和IP的内容，实现远转移。**

![](https://img-blog.csdnimg.cn/20200204221219642.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

ret指令相当于： pop IP

retf 指令相当于： pop IP

pop CS

## call

call指令：（1）将当前的IP或CS和IP压入栈

（2）转移

- **依据位移的call指令**

call 标号（将当前ip压栈，转到标号处执行指令）

![](https://img-blog.csdnimg.cn/20200204221824324.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

```assembly
push IP

jmp near ptr 标号
```



- **转移目的地址在指令中的call指令**

![](https://img-blog.csdnimg.cn/20200204222408755.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

call far ptr 标号 相于：

```assembly
push CS
push IP
jmp far ptr 标号
```

- **转移地址在寄存器中的call指令**

![](https://img-blog.csdnimg.cn/20200204222437100.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

相当于：

```assembly
push IP
jmp 16位reg
```

- **转移地址在内存中的call指令**

![](https://img-blog.csdnimg.cn/20200204222454899.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20200204222504371.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### call和ret的配合使用

![](https://img-blog.csdnimg.cn/20200205144331473.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

call指令转去执行子程序，ret返回。

### mul指令

**mul是乘法指令。**注意以下两点

1. **两个相乘的数，两个相乘的数，要么都是8位，要么都是16位。如果是八位，一个默认放在AL中，另一个放在8位reg或内存字节单元中；如果是16位，一个默认在AX中，另一个在16位reg中或内存字单元中。**
2. **结果：如果是8位乘法，结果默认放在AX中；如果是16位乘法，结果高位默认放在DX中，低位放在AX中。**

格式：mul reg

mul byte ptr

mul word ptr



用寄存器来存储参数和结果是最常见的方法。

批量数据时，我们将批量数据放到内存中，然后将它们的所在空间的首地址放在寄存器中，传递给需要的子程序。对于有批量数据的返回结果，也用同样的方法。

### 寄存器冲突

![](https://img-blog.csdnimg.cn/20200205145736817.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

## 实验10

```assembly
mov al,0a0h
	dec dh
	mul dh
	mov bx,ax
	
	mov al,2
	dec dl
	mul dl
	add bx,ax
```

计算偏移量

```assembly
push ax
	
	mov ax,dx
	mov dx,0  ;Clear the DX of 16 bits higher than the divisor
	div cx  ;int(H / N)
	mov bx,ax  ;Temporary high int (H / N) quotient,Now DX is REM (H / N)
	
	pop ax
	div cx
	mov cx,dx
	mov dx,bx
```

**把一个数放在dx中即在高位寄存器，自动就乘了65536**

![](https://img-blog.csdnimg.cn/20200207134231753.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

**十进制数码字符对应的ASCII码=十进制数码值+30H**

十进制数码：

![](https://img-blog.csdnimg.cn/20200207134245748.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

```assembly
otc:
	push cx
	mov cx,ax
	jcxz transposition
	pop cx
	mov dx,0
	div bx
	mov ds:[di],dl
	add byte ptr ds:[di],30h
	inc di
	inc cx
	jmp short otc
	
transposition:
	pop cx
	mov byte ptr [di],0
	dec di
	mov ax,cx
	mov bl,2
	div bl
	mov cl,al
	s:
		mov al,ds:[di]
		mov bl,ds:[si]
		mov ds:[di],bl
		mov ds:[si],al
		inc si
		dec di
		loop s 
```

还需要调换位置！！！