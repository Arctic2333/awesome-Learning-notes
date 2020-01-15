# unit 3

## 内存中字的存储

在内存存储时，由于内存单元是字节单元（一个单元存放一个字节），则**一个字要用两个地址连续的内存单元来存放。**

字单元，即存放一个字型数据（16位）的内存单元，由两个地址连续的内存单元组成。**高地址内存单元存放字型数据的高位字节，低地址内存单元存放字型数据的低位字节。**

起始地址为0的字单元存放4E20H 则 20存放在0号单元（低位字节），4E存放在1号单元（高位字节）。

- 起始地址为N的字单元简称为N地址字单元。
- 任何两个连续的内存单元，N号单元和N+1号单元，可以看成两个内存单元，也可以看作一个地址为N的字单元的高位字节和低位字节单元。

## DS和[address]

8086CPU中有一个DS寄存器，通常用来存放要访问数据的段地址。

数据从内存单元到寄存器的格式： **mov 寄存器名,内存单元地址(用“[]”括起来)**

从寄存器到内存单元的格式：**mov 内存单元地址，寄存器名**

**[]**表示一个内存单元，“【】“中的数字表示内存单元的偏移地址。我们知道只有偏移地址是不能确定一个内存单元的。所以执行时**8086CPU自动取DS中的数据为内存单元的段地址。**

**8086CPU不支持数据直接送入段寄存器的操作。**只能用一个寄存器作为中转，**先将数据送入一个一般寄存器**，如bx，**再将bx中的数据送入DS。**

## 字的传送

8086是16位结构。只要在mov指令中给出16位的寄存器就可以进行16位数据的传送了。

如：

![](https://img-blog.csdnimg.cn/20200115121525127.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20200115121547102.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

- **mov，add，sub 指令中[num] ：num都是字单元的起始地址，也就是低位字节，num+1是高位字节，num和num+1共同构成一个数据。**

