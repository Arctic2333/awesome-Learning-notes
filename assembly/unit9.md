# unit 9

**可以修改IP，或同时修改CS和IP的指令统称为转移指令。**

### 转移行为：

- **段内转移**：

1. **短转移**（ip修改范围：-128~127）
2. **近转移**（ip修改范围：-32768~32767）

- **段间转移**（远转移）

### 转移指令：

- 无条件转移指令（jmp）
- 条件转移指令（jcxz）
- 循环指令（loop）
- 过程
- 中断

## offset

操作符offset 的功能是取得标号的偏移地址。

例子：

s和s0的指令所在的内存单元的地址是？

cs：offset s

cs：offse s0



**nop的机器码占一个字节 两个nop等于一个字**

## jmp指令

jmp为无条件转移指令，可以只修改ip，也可以同时修改CS和IP。

### **依据位移进行转移的jmp指令：**

- **jmp short 标号（转到标号处的指令）**（段内短转移）

short ：指令进行的是短转移

标号：指令要转移的目的地

这类jmp-->cpu执行时并不需要转移的目的地址而是位移量。

cpu执行指令的顺序：

![](https://img-blog.csdnimg.cn/202002041127378.PNG)

![](https://img-blog.csdnimg.cn/2020020411273583.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

- **jmp near ptr 标号**（段内近转移）

![](https://img-blog.csdnimg.cn/20200204112744910.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

#### 位移量：目的地址-jmp后一条地址的第一个字节的地址

### 转移的目的地址在指令中的jmp指令：

**jmp far ptr 标号**（段间转移，又称远转移）

far ptr 指明了指令用标号的段地址和偏移地址修改cs和ip

假如：jmp far ptr s 的机器码为：EA 0B 01 BD 0B 其中包含转移的目的地地址。

“0B 01 BD 0B” 是目的地址在指令的存储顺序，高地址的“BD 0B”就是段地址“0BBDH”

低地址“0B 01”是偏移地址“010BH”



**上面两种jmp指令的区别在于指令对应的机器码，第一种只包含偏移的位移，第二种是包含目的的段地址和偏移地址。**



### 转移地址在寄存器中jmp指令

指令格式：jmp 16位reg

功能：（IP）= （16位reg）

### 转移地址在内存中的jmp指令

**（1）jmp word ptr 内存单元地址（段间转移）（只改IP）**

对应数据 dw

功能：从内存单元地址处开始存放着一个字，是转移的目的偏移地址

**（2）jmp dword ptr 内存单眼地址（段内转移）（改IP和CS）**

对应数据 dd

功能：从内存单元地址开始存放着两个字，高地址的字是转移的目的段地址，低地址是转移的目的偏移地址

（CS）=（内存单元地址+2）

（IP）=（内存单元地址）

## jcxz指令

jcxz指令为有条件的转移指令。所有的有条件转移指令都是短指令。对应的机器码只包含转移的位移

指令格式:**jcxz 标号（如果（cx）=0，转移到标号处执行）**

![](https://img-blog.csdnimg.cn/2020020412072598.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### loop指令

loop指令为循环指令，所有的循环指令都是短指令。对应的机器码只包含转移的位移

指令格式：**loop 标号（（cx）=（cx）-1，如果（cx不等于0），转移到标号处执行）**

![](https://img-blog.csdnimg.cn/2020020413535298.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

## 实验8

![](https://img-blog.csdnimg.cn/20200204140136415.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

## 实验9

test.asm(7): error A2009: Symbol not defined: B9H

说明：此错误信息为test.asm中第7行指令出错，查看该指令，源操作数为十六进制数B9H。按规定以字母开始的十六进制数，应在其前面加上数字0以便汇编程序区分常数和符号。另一种出错的可能原因是程序中使用的符号变量没有定义

可以利用jmp 实现程序保持运行。

```assembly
all:
		jmp short all
		mov ax,4c00h
		int 21h
```

