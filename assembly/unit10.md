# unit 10

call 和 ret 指令都是转移指令，它们修改IP，或同时修改CS和IP。

## ret 和 retf

**ret指令用栈中的数据，修改IP的内容，实现近转移**

**retf指令用栈中的数据，修改CS和IP的内容，实现远转移。**

![](https://img-blog.csdnimg.cn/20200204221219642.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

ret指令相当于： pop IP

retf 指令相当于： pop IP

pop CS

## call

call指令：（1）将当前的IP或CS和IP压入栈

（2）转移

- **依据位移的call指令**

call 标号（将当前ip压栈，转到标号处执行指令）

![](https://img-blog.csdnimg.cn/20200204221824324.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

```assembly
push IP

jmp near ptr 标号
```



- **转移目的地址在指令中的call指令**

![](https://img-blog.csdnimg.cn/20200204222408755.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

call far ptr 标号 相于：

```assembly
push CS
push IP
jmp far ptr 标号
```

- **转移地址在寄存器中的call指令**

![](https://img-blog.csdnimg.cn/20200204222437100.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

相当于：

```assembly
push IP
jmp 16位reg
```

- **转移地址在内存中的call指令**

![](https://img-blog.csdnimg.cn/20200204222454899.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

![](https://img-blog.csdnimg.cn/20200204222504371.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

