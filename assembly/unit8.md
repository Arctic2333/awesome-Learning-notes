# unit 8

(1)处理的数据在什么地方？

(2)要处理的数据有多长？



reg表示一个寄存器（ax、bv、cx、dx、ah、al、bh、bl、ch、cl、dh、dl、sp、bp、si、di）

sreg表示一个段寄存器（ds、ss、cs、es）



在8086CPU中，**只有bx、si、di、bp这4个寄存器可以用在[。。。]中来进行内存单元的寻址。**

**在[.......]中，这4个寄存器可以单个出现，或只能以4种组合出现：bx和si、bx和di、bp和si、bp和di**

[.......]指令中没由显性地给出段地址。**bp默认段地址在ss种，bx、si、di默认段地址在ds中。**



指令执行的前一刻，数据可以在3个地方：CPU内部、内存、端口



### 数据的位置

1. 立即数（idata），在汇编指令中直接给出，指令执行前数据在CPU的指令缓冲器中。
2. 寄存器，在汇编指令中给出相应的寄存器名，数据在寄存器中。
3. 段地址（SA）和偏移地址（EA），数据在内存中，在汇编指令[。。]中给出EA，SA在某个段寄存器中。



### 寻址方式

有5中寻址方式：直接寻址、寄存器间接寻址、寄存器相对寻址、基址变址寻址、相对基址变址寻址

![](https://img-blog.csdnimg.cn/20200201150509558.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

一个寄存器-->寄存器xx寻址

+idata -->就是相对

两个寄存器 -->xx基址变址寻址

## 数据长度

可以处理的两种长度的数据：byte和word

（1）通过寄存器名指明要处理的数据的尺寸

（2）操作符X ptr指明内存单元的长度，X在汇编指令中为word或byte。

- word ptr指明了指令访问的内存单元是一个字单元
- byte ptr指明了指令访问的内存单元是一个字节单元（在没有寄存器参与的内存单元访问指令是必不可少的）

push、pop指令只进行字操作



**[bx+idata+si] or [bx].idata[si]访问结构体内的数据。用bx定位整个结构体、用idata定位结构体中的某一个数据项，用si定位数据项中的每个元素**



## div指令

div是除法指令

1. **除数：有8位和16位两种，在一个reg或者内存单元中。（8或16具体由ptr指明或寄存器名称）**

2. **被除数：默认放在ax或dx和ax中，如果除数为8位，被除数则为16位，默认在ax中存放；**

   **如果除数是16位，被除数则为32位，在DX和AX中存放，dx存放高16位，ax存放低16位。**

3. **结果：如果除数为8位，则AL储存除法操作的商，AH储存除法操作的余数**

   **如果除数为16位，则ax存储除法操作的商，dx存储除法操作的余数**

格式：div reg

div 内存单元



伪指令dd

dd是用来定义dword（double word）型数据的（32位）



dup是一个操作符，它和db、dw、dd等数据定义的伪指令配合使用，用来进行数据重复。

db 3 dup （0）    == db 0，0，0

db 3 dup （0，1，2）== db 0，1，2，0，1，2，0，1，2

使用格式：

dp 重复次数 dup （重复的字节型数据）

dw 重复次数 dup （重复的字型数据）

dd 重复次数 dup （重复的双字节型数据）

## 实验七思路与总结

![](https://img-blog.csdnimg.cn/20200202135846997.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

