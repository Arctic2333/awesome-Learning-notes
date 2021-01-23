# unit 14

CPU可以直接读写以下3个地方：

1. CPU内部的寄存器
2. 内存单元
3. 端口

CPU最多定位64kb个不同端口

**端口的读写指令只有两个：in和out**

***从端口读取数据：in***

***向端口写入数据：out***

在in和out指令中，只能使用ax或al存放从端口中读入的数据或要发生到端口中的数据。

访问8位端口时用al，访问16位端口用ax

70h为地址端口，存放要访问的CMOS单元的地址；71h为数据端口。存放从选定的CMOS单元中读取数据，或要写入的其它数据。

例如：读取CMOS的2号单元的数据：

```assembly
mov al,2
out 70h,al
in al,71h
```



## shl和shr指令

shl是逻辑左移指令：

1. 将一个寄存器或内存单元中的数据向左移位
2. 将最后移出的一位写入CF中
3. 最低位用0补充

如果移动位数大于1时，必须将移动位数放在cl中

将x左移一位，相当于执行x=x*2

格式 : shl al,1

shl al,cl

shr是逻辑右移指令：

1. 将一个寄存器或内存单元中的数据向右移位
2. 将最后移出的一位写入CF中
3. 最高位用0补充

如果移动位数大于1时，必须将移动位数放在cl中

将x右移一位，相当于执行x=x/2



## 时间信息

![](https://img-blog.csdnimg.cn/20200212170245745.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

**BCD码值=十进制码值，则BCD码值+30h=十进制对应的ASCII码**

一个字节两个BCD码

```assembly
mov al,8
out 70h,al
in al,71h  ;al从CMOS的第八单元中读出月的数据

mov ah,al
mov cl,4
shr ah,cl  ;ah中月份的十位数码值
and al,00001111b  ;al中月份的个位数码值
```

