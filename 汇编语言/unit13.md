# unit 13

### int 指令

格式: int n, n 为中断类型码，它的功能是引发中断

执行过程：

1. 取中断码n

2. 标志寄存器入栈 IF = 0，TF =0

3. CS、IP入栈

4. （IP）=（n*4）

   （CS）=（n*4+2）

**int 的最终功能和Call相似，都是调用一段程序。**

int 指令 和 iret配合使用。  interrupt ret



**串操作 ds：si源地址**

**es：di 目的地址**



中断例程：

- 安装程序（把中断处理程序copy到内存）
- 设置中断向量表
- 中断处理程序

注意:处理寄存器冲突



![](https://img-blog.csdnimg.cn/20200211141823358.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20200211142345162.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### BIOS ：

1. 硬件系统的检测和初始化程序；
2. 外部中断和内部中断例程
3. 用于对硬件设备进行I/O的中断例程
4. 其他和硬件系统相关的中断例程



可以用int 指令直接调用BIOS或DOS提供的中断例程

BIOS和DOS提供的中断例程，都用**ah来传递内部子程序的编号。**



int 10h中断例程的设置光标位置功能：

```assembly
mov ah,2  ;设置光标的子程序 第二个
mov bh,0  ;第0页
mov dh,5  ;dh中放行号
mov dl,12  ;dl中放列号
int 10h
```

int 10h中断例程的在光标位置显示字符的功能：

```assembly
mov ah,9  ;在光标位置显示字符
mov al,'a'  ;字符
mov bl,7  ;颜色属性
mov bh,0  ;第0页
mov cx,3  ;字符重复个数
int 10h
```

int 21h中断例程在光标位置显示字符串

```assembly
ds:dx 指向字符串 ;要显示的字符串需要“$”作为结束符
mov ah,9  
int 21h
```

