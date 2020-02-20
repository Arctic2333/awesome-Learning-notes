# unit 1

![](https://img-blog.csdnimg.cn/20200218124016571.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20200218124123386.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### 计算机系统：

- 硬件 计算机的实体
- 软件 由具有各类特殊功能的信息（程序）组成

#### 软件：

1. 系统软件 用来管理整个计算机系统
   - 语言处理系统
   - 操作系统
   - 服务性程序
   - 数据库管理系统
   - 网络软件
2. 应用软件 按任务需要编制成的各种程序

![](https://img-blog.csdnimg.cn/20200218124609125.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

## 计算机系统的层次结构

![](https://img-blog.csdnimg.cn/20200218131137740.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20200218131149232.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

## 计算机系统结构和计算机组成

- 计算机系统结构 机器语言程序员所见到的计算机系统的属性概念性的结构与功能特性

（指令系统、数据类型、寻址技术、I/O机理   例如：有无乘法指令）

- 计算机组成  实现计算机体系结构所体现的属性

  （具体指令的实现   例如：如何实现乘法指令）

  ## 冯*诺依曼计算机的特点

**提出了“存储程序”的概念**

特点：

![](https://img-blog.csdnimg.cn/20200218132125698.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)



硬件框图：

![](https://img-blog.csdnimg.cn/20200218132451147.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

- **运算器用来完成算术运算和逻辑运算，并将运算的中间结果暂存在运算内。**
- 存储器用来存放数据和程序。
- **控制器用来控制、指挥程序数据的输人、运行以及处理运算结。**
- 输人设备用来将人们熟悉的信息形转换为机器能识别的信息形式，常见的有键盘、鼠
  标等。
- 输出设备可将机器运算结果转换为人们熟悉的信息形式如打印机输出、显示器输出等。



**现代计算机可以认为由3大部分组成：CPU、I/O设备及主存储器**

*CPU和主存储器构成主机*

![](https://img-blog.csdnimg.cn/20200218132942347.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### 存储器的基本组成

- 存储体

- MAR 存储器地址寄存器 反映存储单元的个数   （功能：寻址）

- MDR 存储数据寄存器 反映存储字长 （每一份数据的长度）

  设MAR=4 位 MDR=8位  则存储单元个数：16 （2的4次方） 存储字长 8位

### 运算器的基本组成

![](https://img-blog.csdnimg.cn/20200218134205196.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

举例 加法过程：

![](https://img-blog.csdnimg.cn/20200218134211772.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### 控制器

**控制器的功能：**

- 解释指令
- 保证指令的按序执行

**控制器的基本组成**（完成一条指令）

1. 取指令 **PC**   PC存放当前欲执行指令的地址，具有计数功能（PC）+1-->PC
2. 分析指令 **IR** IR存放当前欲执行的指令
3. 执行指令 CU  译码器 发出控制信号



运算器和控制器构成CPU

运算器和控制器、主存构成主机



**完成一条指令的过程：**

![](https://img-blog.csdnimg.cn/20200218135303742.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

#### 技术指标：

- 机器字长  CPU一次能处理数据的位数与CPU中的寄存器位数有关

- 运算速度

  主频
  核数，每个核支持的线程数
  吉普森法
  CPI执行一条指令所需时钟周期数
  MIPS每秒执行百万条指令
  MFLOPS每秒浮点运算次数

- 存储容量   存放二进制信息的总位数

主存容量

存储单元个数×存储字长
如MAR   MDR容量

​     10        8       1k*8位    1k = 2的10次方

字节数  如   2的13次方  b  = 1KB  



辅存容量   字节数 



汇编对微操作  一对多  即一条微指令对多条微操作

汇编对微指令 一对一

汇编对机器语言 一对一   机器语言就是微程序