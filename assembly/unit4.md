# unit 4

## 伪指令

#### segment 和 ends

segment和ends是一对成对使用的伪指令。segment和ends的功能是定义一个段，segment说明一个段开始，ends说明一个段结束。格式：

**段名 segment**

**段名 ends（可以理解为 end segment）**

一个有意义的汇编程序中至少有一个段，这个段来存放代码

#### end

end 是一个汇编程序的结束标志

end就是结束对汇编程序的编译

#### assume

“假设”，它假设某一个段寄存器和程序中的某一个用segment 和 ends定义的段相关联。

**编程时，记得用 assume 将特定用途的段和相关的段寄存（cs、ds、ss、）器相关联。**



用汇编语言写的源程序，包括伪指令和汇编指令。

标号。比如“codesg”。一个标号指代一个地址。

![](https://img-blog.csdnimg.cn/20200117161737226.PNG)

程序返回：一个程序结束后，将CPU的控制器交还给**使得它运行**的程序。

**连接的作用：**

![](https://img-blog.csdnimg.cn/20200117162123462.PNG)

1.asm 通过编译 --> 1.obj   (masm)

1.obj   通过连接 --> 1.exe  (link)

#### 寄存器器cx中存放程序的长度

### exe文件中程序的加载过程

![](https://img-blog.csdnimg.cn/20200117162452825.PNG)

**256个字节   16的2次方  即 10H**

所以 cs -10H即psp区的起始位置  因为ds = sa 即 ds也是psp区的起始位置

**查看psp 区的内容 -d ds：0即可** **psp区头两个字节是 CD，20**

- **当debug 执行到 int 21 要用p命令执行**