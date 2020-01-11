# **Unit_1**

- 安卓系统由4层组成，分别是**操作系统、中间件、用户界面和应用软件**。

- 安卓开发中，代码的编写是在**Android Studio**的**app**目录下。

- **res**目录下 ：图片放在**mipmap**目录下，布局放在**layout**目录下，字符串放在**values**目录下。

- **AppCompatActivity**是一种**向下兼容**的Activity，可以将activity在各个版本增加的特性和功能最低兼容到Android2.1.

  ### 开发中所有的自定义的Activity都必须继承自Activity或者Activity的子类才拥有Activity的特性。

- View组件是所有UI组件和容器空件的基类。

- 如果需要通过某个Activity把指定的View显示出来，调用Activity的setContentView()方法即可。

- Service 看作没有View的Activity。

- BroadcastReceiver：广播接受器

- 实现BroadcastReceiver的方式：基础BroadcastReceive的类并重写onReceiver（）方法。

- ContentProvider是一种跨进程间通信。

- Intent （意图）：

  显试Intent：明确指定需要启动或触发的组件类名。

  隐试Intent：指定需要启动或触发的组件应满足怎样的条件

- Android通过IntentFilter来判断是隐试还是显试Intent。

- 

- ### 安卓系统的体系结构

- Application - Application Framework - Libraies - Android Runtime - Linux Kernel

![安卓系统的体系结构](http://images4.pianshen.com/959/ee/ee9e8eb7293288b0c61ffee029216247.png)