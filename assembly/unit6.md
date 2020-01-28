# unit 6

"dw"的含义是定义字型数据。“define word” 在描述dw的作用时，可以说他用于定义数据，也可以说明它开辟内存空间。



**end 除了通知编译器程序结束外，还可以通知编译器程序的入口在什么地方。**

CPU从何处开始执行程序，只要在源程序中用“end 标号” 指明就可以了。

程序框架为:

assume cs:code

code segment

​	data

**start:**

​	code

code ends

end **start**



## 多个段来存放数据、代码和栈

![](https://img-blog.csdnimg.cn/20200128132933939.PNG)

“mov ax，data”的含义就是将名称为data的段的段地址送入ax。

其中“code”、“data”、“stack”只是标号。



**如果段中的数据占N个字节，则程序加载后，该段实际占有空间为N%16=0？N：（N/16+1）*16**

