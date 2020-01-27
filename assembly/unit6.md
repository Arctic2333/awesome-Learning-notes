# unit 6

"dw"的含义是定义字型数据。“define word” 在描述dw的作用时，可以说他用于定义数据，也可以说明它开辟内存空间。



**end 除了通知编译器程序结束外，还可以通知编译器程序的入口在什么地方。**

cpu 从何处开始执行程序，只要在源程序中用“end 标号” 指明就可以了。

程序框架为:

assume cs:code

code segment

​	data

**start:**

​	code

code ends

end **start**

