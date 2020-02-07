# unit 11

![](https://img-blog.csdnimg.cn/20200207134919718.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

# 标志寄存器

flag寄存器是按位起作用的，也就是说，它的每一位都有专门的含义，记录特定的信息。



## ZF标志（zero flag）

flag的第6位是ZF，零标志位，它记录相关指令执行后，其结果是否为0.

- **如果结果为0，那么ZF=1**  （debug 中  ZR） ZERO

- **如果结果不为0，那么ZF=0**（debug 中  NZ）NOT ZERO



有的指令的执行对标志寄存器**没有影响**，比如，mov、push、pop等，它们多数是**传送指令**

有的指令的执行对标记寄存器**有影响**，比如，sub、mul、div、dec、add、or等，它们大多是**运算指令。**



## PF标记（parity flag）

falg的第2位是PF，奇偶检验标志位，他记录相关指令执行后，其结果的所有bit’位中1的个数是否为偶数。

- **如果1的个数是偶数，pf=1**( DEBUG   PE  \)  parity even

- **如果1的个数是奇数，pf=0**(DEBUG PO) parity odd



## SF标记（sign flag）

flag的第7位是SF，符号标志位，它记录相关指令执行后，其结果是否为负

- **如果结果为负，SF=1** （DEBUG  NG）negative 负数
- **如果不为负，SF=0**（DEBUG PL）positive plus zero 正数加零

SF标记是对CPU对**有符号数运算**结果的一种记录

![](https://img-blog.csdnimg.cn/20200207142521172.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### **注意如果的描述**   既要考虑有符号运算也要考虑无符号运算

**这种对有符号的寄存器（SF、OF） 为有符号运算**

**无符号寄存器（CF）为无符号运算**

有符号 -128 ~127  1000 0000 ~ 0111 1111   **大于 0111 1111（7FH）为负数**

-32768~32767 ~0111 1111 1101 0111‬   **大于7FD7 为负数**

无符号

255

65535



## CF标志（carry flag）

flag 的第0位是CF，进位标志位。在进行**无符号数运算**的时候，它记录了运算的最高有效位**向更高位的进位值（加法），或从更高位的借位值（减法）**

![](https://img-blog.csdnimg.cn/20200207144110146.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

当有进位或借位时：CF为1



## OF标志（over flag）

8位有符号数据，机器所能表示的范围就是-128~127，16位有符号数据，能表示的数据范围：-32768~32767

flag 的第11位是OF，溢出标志位，一般情况下，OF记录了有符号数运算的结果是否发送溢出

- **如果发送溢出，OF=1；**
- **如果没有，OF=0**



### adc指令

adc是带进位加法指令，它利用了CF位上记录的进位值

指令格式：adc 操作对象1，操作对象2

功能：操作对象1 = 操作对象1 + 操作对象2 + CF

adc ax，cx  （ax）=（ax）+（cx）+CF

**加法可以分两步进行：1、低位相加；高位相加再加上低位相加产生的进位值。**   （所有的加法都能分解 从低到高，以字为单位或字节为单位）

**inc 和 loop 指令不影响CF位**

![](https://img-blog.csdnimg.cn/20200207152228576.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### sbb指令

sbb是带借位的减法，它利用了CF位上的借位值

![](https://img-blog.csdnimg.cn/20200207153620770.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

 1、低位相减

2、高位相减，减去借位值



## cmp指令

cmp是比较指令，cmp的功能相当于减法指令，只是不保存结果。cmp指令执行后，将对标志寄存器产生影响。

![](https://img-blog.csdnimg.cn/20200207154716789.PNG)

无符号运算：

![](https://img-blog.csdnimg.cn/20200207154726401.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

有符号：

![](https://img-blog.csdnimg.cn/20200207154738168.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)



### 检测比较结果的条件转移指令（与cmp用）

更改IP

![](https://img-blog.csdnimg.cn/2020020715502632.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)



## DF标志（direction flag）和串传送指令

flag 的第10位是DF，方向标志。在串处理指令中，控制每次操作后si、di的增减。

- **df = 0 每次操作后 si、di递增 （debug   UP）**
- **df =1 每次操作后si、di递减   （debug dn）down**

### 串处理指令：

格式:movsb

功能：![](https://img-blog.csdnimg.cn/20200207161739339.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

movsb的功能是将**di：si**指向内存单元中的**字节**送入**es：di**中，然后根据df的值，使di和si递增或递减。

![](https://img-blog.csdnimg.cn/20200207161755827.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

**rep 的作用是根据cx的值，重复执行后面的串传送指令。**



#### cld指令：将df的位置设为0 ， 递增

#### std指令:将df的位置设为1，递减



### pushf和popf

- **pushf的功能是将标志寄存器的值压入栈**
- **popf是从栈中弹出数据，送入标志寄存器**

pushf和popf，为直接访问标志寄存器提供了一种方法。