# unit 1

## 计算机系统的层次结构

![](https://img-blog.csdnimg.cn/20200222150318976.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

各机器级的实现采用**翻译技术**或**解释技术**，或者是这两种技术的结合。

- 翻译 : 高一级的机器 的 程序整个地变换成低一级机器上
- 解释： 低一级的机器级上用它的一串语句或指令仿真高级机器级上的一条语句或指令的功能

## 计算机系统结构的定义和内涵

系统结构是对计算机系统中**各级界面的定义及其上下的功能分配**。计算机系统的每一级都有自己的系统结构。

- **经典定义**：传统机器程序员所看到的计算机属性及概念性结构和功能特性（例如：有没有乘法指令什么的）

- **广义定义**：系统结构包括计算机设计的三个方面：指令系统结构、计算机组成、和微体系结构硬件。

- **它是软件和硬件的交界面，是机器语言、汇编语言程序设计者，或编译程序设计者看到的机器物理系统的抽象。**

  ![](https://img-blog.csdnimg.cn/20200222152150946.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)



### 计算机组成：

计算机组成指的是计算机系统结构的逻辑实现，包括机器级内部的数据流和控制流的组成以及逻辑设计等。

### 计算机实现：

计算机实现指的是计算机组成的物理实现，着眼于器件技术和微组装技术，其中器件技术起着主导作用。

![](https://img-blog.csdnimg.cn/20200222154210287.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

I：指令系统：用硬件实现的命令集，软硬件的界面。

P：处理模块  S：存储模块  N：互联网模块



**软、硬件的功能分配是计算机系统结构的主要任务，而软件和硬件在逻辑功能上又是等效的**



## 计算机追求的目标：快

方法：

1. 辨认经常性事件
2. 找出加快的方法

3个例子：

- **复杂指令集系统**  CISC

指令代替子程序                      

较少的寄存器

简洁的代码     ------------------> 复杂的硬件

硬件代替软件                           复杂的指令集

- **精简指令集系统** SISC

精简的指令集

更简单的硬件

较多的寄存器

更多的代码行

- **高速Cache**

局部性原理

![](https://img-blog.csdnimg.cn/20200222164156164.PNG)

## 评价计算机性能：

![](https://img-blog.csdnimg.cn/20200222155919218.PNG)

![](https://img-blog.csdnimg.cn/20200222155928277.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

不同层次的基准程序来评测：

1. 实际的应用程序测试
2. 核心程序测试
3. 合成测试程序
4. 综合基准测试程序

## 计算机系统的定量设计原理：

- 哈夫曼压缩原理  ：频度高的指令用短码，频度低的指令用长码  在指令系统中使用
- Amdahl定律
- 程序访问的局部性定律  ：时间上和空间上的两个局部性。

![](https://img-blog.csdnimg.cn/20200222161158920.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### Amdahl 定律：

加速比定义：

 Sn = 新速度/老速度 = 老时间（总时间）/新时间 = T0/Tn

定律：**系统加速比Sn = 1/（1-Fe）+Fe/Se**

Se：被改进部分的部件加速比

Fe：被改进部分原执行时间占原来总时间的百分比

Tn=T0（1-Fe+Fe/Se）   

 Fe-->0,Sn-->1

![](https://img-blog.csdnimg.cn/20200222162016597.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

Amdahl定律的性能递减规则：

如果仅仅对计算机中的一部分做性能改进，则改进越多，所得到的总体性能的提升就越有限。

![](https://img-blog.csdnimg.cn/20200222162009181.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)



### CPU性能公式

CPU时间：一个程序在CPU上运行的时间，不包括I/O时间  = 执行程序所需的时钟周期*时钟周期时间（时钟频率的倒数   固有属性）

1.时钟周期时间：系统的时钟周期时间越短，CPU的性能就越好

2.指令周期数CPI：平均每条指令消耗的时钟周期数

CPI = 执行程序所需的时钟周期数/IC    IC：所执行的指令条数

CPU时间 = IC * CPI * 时钟周期时间

​                =  IC  *  CPI /  时钟频率

优化CPU的策略：

- 减少指令的条数
- 降低CPI
- 减少时钟周期

![](https://img-blog.csdnimg.cn/20200222164633661.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20200222164203256.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

## 计算机系统设计的主要任务和方法

主要任务包括系统结构、计算机组成和计算机实现的设计。

多核处理器设计、片上网络、并行编程模型、节能

系统建构师：1.look backward

2.look forward

3.look up

4.look down

图灵机-计算机的（理论基础）

冯诺依曼体系结构（架构基础）

摩尔定律（物质基础）

Amdahl定律（计算机系统结构的总原则）

## 并行性

**并行性**:计算机系统在同一时刻或者是间隔内多种运算或操作，包含

- 同时性：两个或两个以上的事件在同一时刻发生
- 并发性：两个或两个以上的事件在同一时间间隔内发生

从处理数据的角度来看，并行性等级从低到高可分为：

1. 字串位串  ：  每次只对一个字的一位进行处理
2. 字串位并  ：  同时对一个字的全部位进行处理，不同字中间是串行
3. 字并位串  ：  同时对多个字的同一位（称为位片）进行处理
4. 全并行  ：  同时对许多字的全部位或部分位进行处理

从执行程序的角度来看，并行性等级从低到高可分为：

- 指令级并行：并行执行两条或两条以上的指令
- 线程级并行：并行执行两个或两个以上的线程
- 任务级或过程级并行：并行执行两个或两个以上的过程或任务（程序段）
- 作业或程序级并行：并行执行两个或两个以上的作业或程序

### **提高并行性的方法：**

1. 时间重叠：**流水线技术**  （五大流水线：取指、译码、执行、访存、写回）：引入时间因素，让多个处理过程在时间上相互错开，轮流重叠地使用同一套硬件设备的各个部分，以加快硬
   件周转而赢得速度

2. 资源重复：引入空间因素，以数量取胜。通过重复设置硬件资源，大幅度地提高计算机系统的性能

   主要运用在**多体存储器、多操作部件和阵列处理机**上

3. 资源共享：软件方法，使多个任务按一定时间顺序轮流使用同一套硬件



多机系统遵循时间重叠、资源重复、资源共享原理，发展为3种不同的多处理机：

- 同构型多处理机（資源重复）目的：为了提高系统的性能
- 异构型多处理机（时间重叠）目的：为了提高系统的效率
- 分布式系统 目的：兼顾系统的性能和效率



在单机处理中，**资源共享**的概念实质上是用单处理器模拟多处理机的功能





