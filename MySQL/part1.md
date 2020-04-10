### MySQL服务的启动和停止

```mysql
方式1：计算机-右击管理-服务

方式2：通过管理员运行cmd

net start 服务名（启动服务）

net stop 服务名 （停止服务）
```

### MySQL服务的登录和退出

```mysql
方式1：通过mysql自带的客户端
只限于root用户
方式2：通过cmd
mysql 【-h主机名 -p端口号】 -u用户名 -p密码

退出
exit或ctrl+c
```

### MySQL的常见命令

```mysql
1.查看当前所有的数据库
show databases；
2.打开指定的库
use 库名
3.查看当前库的所有表
show tables；
4.查看其他库的所有表
show tables form 库名；
5.创建表
create table 表名（
	列名 列类型
	。。。
）；
6。查看表结构
desc 表名；
7.查看服务版本
方式一： select version（）；
方式二： mysql --V
```

### MySQL的语法规范

```mysql
1.不区分大小写，关键字大写，表名、列名小写
2.每条命令最后用分号结尾
3.每条命令如果根据需要，可以缩进或换行
4.注释
	单行注释： #注释文字
	-- 注释
	多行: /* 注释文字*/
```

### SQL

1. DQL
2. DML
3. DDL
4. TCL

