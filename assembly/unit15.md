# unit 15

CPU除了运算能力外，还要有I/O能力。

外设接口芯片内部有若干寄存器，CPU将这些寄存器当作端口来访问，可见CPU通过端口和外部设备进行联系。

### 外中断信息

1.可屏蔽中断

CPU可以不响应的外中断。CPU是否响应可屏蔽中断要看寄存器IF位的设置。

IF=1，则CPU在执行完当前指令后响应中断。

IF=0，不响应可屏蔽中断。

sti，设置IF=1

cli，设置IF=0



2.不可屏蔽中断

CPU必须响应的外中断

不可屏蔽中断的中断类型码固定为2，所以中断过程中，不需要取中断类型码。



### 键盘输入：

寄存器的端口位置为：60h

按下一个键时产生的扫描码称为通码，松开一个键产生的扫描码称为断码。

通码的第七位为0，断码的第七位为1

断码=通码+80h



### int 9 号中断

int 9h中断例程，用来进行基本的键盘输入处理。如下：

![](https://img-blog.csdnimg.cn/20200215235907764.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

- 高位字节存放扫描码，低位字节存放字符码



新的中断处理程序要调用到原来int 9中断例程，所以把原来int 9中断例程的偏移地址和段地址保持在ds:[0]和ds:[2]中，也不能用int 来调用，要模拟：

1. 标志寄存器入栈

2. IF=0，TF=0

3. CS、IP入栈

4. （IP）=（（ds）*16+0）

   （CS）=（（ds）*16+2）



CPU对外设输入的处理办法：

1. 外设输入送入端口
2. 向CPU发出可屏蔽中断信息
3. CPU检测到可屏蔽中断信息，如果IF=1，CPU在执行完当前指令后响应中断，执行相应的中断例程
4. 可在处理中断例程中实现对外设输入的处理

![](https://img-blog.csdnimg.cn/20200216142815520.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

可以精简为 pushf

call dword ptr ds:[0]



```assembly
cli

mov word ptr es:[9*4],offset int9

mov word ptr es:[9*4+2],cs

sti


```

