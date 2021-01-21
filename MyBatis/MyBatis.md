# MyBatis

环境：

- JDK1.8
- Mysql 5.7
- maven 3.6.1
- IDEA

 学习Mybatis,最好的方式：看官方文档

- MyBatis 是一款优秀的**持久层框架**

- 它支持定制化 SQL、存储过程以及高级映射。

- MyBatis 避免了几乎所有的 JDBC 代码和手动设置参数以及获取结果集。

- MyBatis 可以使用简单的 XML 或注解来配置和映射原生类型、接口和 Java 的 POJO（Plain Old Java Objects，普通老式 Java 对象）为数据库中的记录。

  - Github ： https://github.com/mybatis/mybatis-3/releases

  - 中文文档：https://mybatis.org/mybatis-3/zh/index.html

    ### 1.2、持久化

    数据持久化

    - 持久化就是将程序的数据在持久状态和瞬时状态转化的过程
    - 内存：**断电即失**
    - 数据库(Jdbc)，io文件持久化。
    - **为什么需要需要持久化？**

    - 有一些对象，不能让他丢掉。

    - 内存太贵了

    

    ### 1.3、持久层

    Dao层，Service层，Controller层….

    - 完成持久化工作的代码块
    - 层界限十分明显。

    

    ### 1.4 为什么需要Mybatis？

    - 传统的JDBC代码太复杂了。简化。框架。自动化。
    - 不用Mybatis也可以。更容易上手。 **技术没有高低之分**
    - 优点：
      - 简单易学
      - 灵活
      - sql和代码的分离，提高了可维护性。
      - 提供映射标签，支持对象与数据库的orm字段关系映射
      - 提供对象关系映射标签，支持对象关系组建维护
      - 提供xml标签，支持编写动态sql。

    

## 第一个MyBatis程序

流程：获取MyBatis  ->  创建测试的数据库 -> 编写代码测试 

使用Maven作为包管理工具

导入mabatis包

```xml
<!-- https://mvnrepository.com/artifact/org.mybatis/mybatis -->
        <dependency>
            <groupId>org.mybatis</groupId>
            <artifactId>mybatis</artifactId>
            <version>3.5.2</version>
        </dependency>

```

导入数据库驱动

```xml
        <!-- https://mvnrepository.com/artifact/mysql/mysql-connector-java -->
        <dependency>
            <groupId>mysql</groupId>
            <artifactId>mysql-connector-java</artifactId>
            <version>5.1.47</version>
        </dependency>
```

导入junit单元测试

```xml
        <!-- https://mvnrepository.com/artifact/junit/junit -->
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>4.12</version>
            <scope>test</scope>
        </dependency>
```

偷懒导入lombok支持

```xml
        <!-- https://mvnrepository.com/artifact/org.projectlombok/lombok -->
        <dependency>
            <groupId>org.projectlombok</groupId>
            <artifactId>lombok</artifactId>
            <version>1.18.12</version>
            <scope>provided</scope>
        </dependency>
```

创建数据库

![](https://img-blog.csdnimg.cn/20210121131603369.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)



编写Mybatis核心配置文件

在resources文件夹中新建mybatis-config.xml文件（文件名字可以取其他，官方建议取这个我们就先取这个）文件内容从官方中复制即可。

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE configuration
  PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
  "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
  <environments default="development">
    <environment id="development">
      <transactionManager type="JDBC"/>
      <dataSource type="POOLED">
          <!--driver 需要修改，com.mysql.jdbc.Driver-->
        <property name="driver" value="com.mysql.jdbc.Driver"/>
          <!--url需修改 连接数据库的参数-->
        <property name="url" value="jdbc:mysql://localhost:3306/mybatis?serverTimezone=GMT%2B8&amp;useUnicode=true&amp;characterEncode=UTF-8"/>
          <!--username需修改 mysql登入的用户名-->
        <property name="username" value="root"/>
          <!--passsword需要修改 mysql登入的密码-->
        <property name="password" value="password"/>
      </dataSource>
    </environment>
  </environments>
  <!--mapper先注释 后面解释作用-->
    <!--<mappers>
    <mapper resource="org/mybatis/example/BlogMapper.xml"/>
  </mappers> -->
</configuration>
```

我们先把配置文件写成静态的。参照官方文档我们知道下一步应该先**从 XML 中构建 SqlSessionFactory**

然后**从 SqlSessionFactory 中获取 SqlSession**，官方示例如下：

```java
String resource = "org/mybatis/example/mybatis-config.xml";
InputStream inputStream = Resources.getResourceAsStream(resource);
SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
```

```java
try (SqlSession session = sqlSessionFactory.openSession()) {
  Blog blog = (Blog) session.selectOne("org.mybatis.example.BlogMapper.selectBlog", 101);
}
```

每一个操作都需要用到以上步骤，我们可以将其编写成工具类。

```java
public class MyBatisUtil {

    private static SqlSessionFactory sqlSessionFactory;

    static {
        String resource = "mybatis-config.xml";
        try {
            InputStream inputStream = Resources.getResourceAsStream(resource);
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static SqlSession getSqlSession() {
        return sqlSessionFactory.openSession();
    }
}
```

接下来我们实现实体类（注意类成员名要与数据库字段名相同）：

```java
import lombok.Data;

@Data
public class User {
    private int id;
    private String name;
    private String pwd;

    public User(int id, String name, String pwd) {
        this.id = id;
        this.name = name;
        this.pwd = pwd;
    }
}
```

这里使用lombok @Data注解 @Data帮我们实现 无参构造+getters+setters + toString + equals

接下来与正常JDBC编写不同的是：正常JDBC需要编写定义方法的接口类，然后再去写实现接口的类

mybatis框架下：我们只需要编写接口类，再去写配置文件。

接口类：

```java
public interface UserMapper {
    /**
     * 获取全部用户
     *
     * @return 含全部用户的列表
     */
    List<User> getUserList();
}
```

在同一文件夹下编写UserMapper.xml（也可不在同一文件夹，但是放在同一文件夹有一定好处后面解释）

这个文件官方实例如下：

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
  PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
  "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="org.mybatis.example.BlogMapper">
    <!--查询语句选择select标签 id=接口类中的方法名 resultType 返回类型我们写实体类名字但是要写完整路径，别名后面解释-->
  <select id="selectBlog" resultType="Blog">
    select * from Blog where id = #{id}
  </select>
</mapper>
```

我们的UserMapper.xml：

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.arctic.dao.UserMapper">
    <select id="getUserList" resultType="com.arctic.dao.UserMappe">
        select *
        from mybatis.user;
    </select>
</mapper>
```

namespace=实体类完整路径

接下来编写junit Test

```java
public class UserMapperTest {
    @Test
    public void getUserList(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        List<User> users = userMapper.getUserList();
        for (User user : users) {
            System.out.println(user);
        }
        sqlSession.close();
    }
}
```

运行测试我们出现错误：

![](https://img-blog.csdnimg.cn/20210121205830311.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70#pic_center)

这是因为我们还没有注册UserMapper

我们返回到mybatis-config.xml中注册

```xml
    <mappers>
        <mapper resource="com/arctic/dao/UserMapper.xml"/>
    </mappers>
```

我们还需要在pom.xml中添加resource的路径，因为maven项目默认只在resources文件夹读取resource

```xml
 <build>
        <resources>
            <resource>
                <directory>src/main/resources</directory>
                <includes>
                    <include>**/*.properties</include>
                    <include>**/*.xml</include>
                </includes>
                <filtering>true</filtering>
            </resource>
            <resource>
                <directory>src/main/java</directory>
                <includes>
                    <include>**/*.properties</include>
                    <include>**/*.xml</include>
                </includes>
                <filtering>true</filtering>
            </resource>
        </resources>
    </build>
```

运行结果：

![](https://img-blog.csdnimg.cn/20210121211125581.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70#pic_center)