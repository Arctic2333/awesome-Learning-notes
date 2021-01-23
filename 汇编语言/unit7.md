# unit 7

![](https://img-blog.csdnimg.cn/20200130145619580.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

## and 和 or 指令

**and指令：逻辑与指令，按位与运算**

例如：

mov al，01100011B

and al，00111011B

结果 al = 00100011B

**通过该指令可将操作对象的相应位设为0，其他位不变。**

例如;

将al的第6位设为0的指令：and al，10111111B

将al的第7位设为0的指令：and al，01111111B



**or指令：逻辑或指令，按位或运算**

例如:

mov al,01100011B

or al,00111011B

结果 al=01111011B

**通过该指令可以将操作对象的相应位设为1，其他位不变。**

将al的第6位设为1的指令是 or al，01000000B



## 关于ASCII码

**用'...........'的方式指明数据是以字符的形式给出的，编译器将把它们转化为相应的ASCII码**

”mov ax，‘a’ ”相当于给出了“mov ax，61H”



大小写转换：

![](https://img-blog.csdnimg.cn/20200130141657648.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

观察可知：小写比大写大32（20H或者100000B）所以将

- **第6位全部设为0 即为大写（and 11011111B）**
- **第6位全部设为1即为小写（or 00100000B）**



[bx+idata] 表示一个内存单元，它的偏移地址为（bx）+idata

c语言：a[i],b[i]

汇编：0[bx],5[bx]

[bx+idata]的方式为高级语言实现数组提供了便利的机制

**si和di是8086CPU中和bx功能相近的寄存器（记录偏移地址，默认段寄存器就是ds），si和di不能分成两个8位寄存器来使用。**

![](https://img-blog.csdnimg.cn/20200130145126919.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

loop默认cx为循环计数器

**一般来说，在需要暂存数据时，我们都应该使用栈。**

两层循环时要先将外层循环的cx入栈。

![](https://img-blog.csdnimg.cn/20200130145455735.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

##     8086CPU 提供将数直接写入内存的功能

![](https://img-blog.csdnimg.cn/20200130154708357.PNG)

​        **但要告诉CPU传送的数据类型**

- **mov byte ptr [bx],5   字节传送**
- **mov word ptr [bx],5  字传送**

 综上所述，立即数是可以写入内存的，但要显式指定传送的数据类型。需要注意的是，用于字节传送的立即数不能大于0ffh；字传送的立即数不能大于0ffffh，否则都会引起值超出范围而无法传送。 