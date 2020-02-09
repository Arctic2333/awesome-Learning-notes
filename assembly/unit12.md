# unit 12

中断的意思是：CPU不再接着执行向下执行，而是转去执行处理这个特殊信息。

中断信息可以来自CPU的内部和外部

**4种情况产生内中断:**

1. 除法错误，比如，执行div指令产生的除法溢出
2. 单步执行
3. 执行into指令
4. 执行int指令

中断类型码的数据来标识中断信息的来源。中断类型码为一个字节型数据。可以表示256种中断信息的来源

1. **除法错误：0**
2. **单步执行：1**
3. **执行into指令:4**
4. **执行int指令，该指令的格式为 int n，指令中的n为字节型立即数，是提供给CPU的中断类型码 例如：int 21H**

用来处理中断信息的程序被成为中断处理程序，需要对不同的信息编写不同的处理程序

中断类型码的作用就是用来定位中断处理程序

### 中断向量表

中断向量表，就是**中断处理程序入口的地址**列表（地址：段地址，偏移地址）

CPU通过8位的中断类型码通过中断向量表找到相应的中断处理程序的入口地址

如果使用8086CPU，中断向量表就必须放在0000：0000~0000：03ff单元中

**一个表项包含两个字，低地址字为偏移地址，高地址存放偏移地址**

![](https://img-blog.csdnimg.cn/20200209152409525.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

存储N号的中断源对应的中断处理程序入口的**偏移地址的内存单元的地址为：4N**

**段地址的内存单元的地址为：4N+2**



用中断类型码找到中断向量，并用它设置CS和IP，这个工作由CPU的硬件自动完成的--->中断过程

**中断过程：**

1. （从中断信息中）取得中断类型码
2. 标志寄存器的值入栈（中断过程要改变标志寄存器的值）
3. **设置标志寄存器的第8位TF和第9位IF的值为0**
4. CS的内容入栈
5. IP的内容入栈
6. 从内存地址为类型码*4和中断类型码*4+2的两个字单元读取中断处理程序的入口地址设置IP和CS

汇编语言：

1. 取得中断类型码N

2. pushf

3. **TF=0，IF=0**

4. push CS

5. push IP

6. （IP）=（N*4），

   （CS）= （N*4+2）

   

### iret指令

中断处理程序：

（1）保持寄存器

（2）处理中断

（3）恢复用到的寄存器

（4）iret返回

iret指令：

pop IP

pop CS

popf





## 编写中断处理程序

一般情况下，从0000：0200至0000：02FF的256个字节对应的向量表项为空，可以放中断处理程序（安全空间）

do0安装程序就是将do0的代码复制带内存0：200的地方

程序目的，安装do0的代码于0：200，将0号处理的中断程序的入口设为0：200

只有在发生0号中断时，do0才是处理程序，其余时候都只是数据。

![](https://img-blog.csdnimg.cn/20200209154832305.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20200209154901322.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

注意点：1.字符串也要放在代码段中

2.字符串前的jmp

**3.编译器可以自己处理四则运算的符号**

jmp 的 长度为2个字节，所以字符串的偏移地址为202h



### 单步中断：

如果检测到寄存器的TF位为1，则产生单步中断，引起中断过程。

TF ： trace flag 跟踪标志

IF：interrupt flag 中断标志





设置段寄器SS的指令 不会响应中断。

放在SS后的指令会在操作SS的指令完成后被立即执行，不响应中断。

所以设置栈顶应该ss和sp设置要连续。



