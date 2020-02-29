```html
<!doctype html>
<html>
	<head>
        <!--head 是网页的头部，head的内容不会在网页中直接出现，帮助浏览器和搜索引擎解析网页-->
        <meta charset="utf-8">
		<!--meta 标签来设置网页的字符集-->
        <!--meta 标志设置网页的元数据-->
		<title> LOVE DRINK</title>
	</head>
	<body> <!--表示网页的主体，网页中所有可见内容都应该写在body-->
		<!--   emmmm  自结束标签 只有 一个 其他都是成对存在-->
		<h1><font color="red">LOVE DRINK </font></h1>
		<h2> ARCTIC </h2>
		<p> luck drink </p>
	</body>

</html>
```

- 属性：在标签中还可以设置属性 属性是一个名值对（x=y）
- 属性用来设置标签中的内容如何显示 属性和标签名或其他属性空格
- 属性不能瞎写 有些有属性值有些没

**doctype  文档声明**

<!doctype html> 声明 是HTML5写的

  <meta charset="utf-8">
		<!--meta 标签来设置网页的字符集-->

vscode !加tab 键直接生成 框架  ctrl + / 注释 tab 补全

<html lang = "en or zh"> en是英语 zh 中文、

- 实体

在网页中编写的多个空格默认情况会自动被浏览器解析为一个空格

在HTML中有些时候，不能直接书写一些特殊符号，比如：多个连续的空格，比如字母两侧的大于和小于号

如果需要在网页中书写这些特殊符号，则需要使用html的实体（转义字符）

实体的语法：

&实体的名字;

- &nbsp；空格
- &gt；大于号
- &lt；小于号
- &copy；版权符号