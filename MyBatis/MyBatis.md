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

## CRUD

我们继续在原来的项目上进行真假增删改查的功能。
我们知道要增加这些功能只需要在原有的UserMapper接口中声明方法和在配置类中实现。
那么此时我们在UserMapper中添加一下几个方法：

 - getUserById
 - update
 - insert
 - delete
 那么我们的UserMapper将会变成：
 ```java
 public interface UserMapper {
    /**
     * 获取全部用户
     *
     * @return 含全部用户的列表
     */
    List<User> getUserList();

    /**
     * 获取用户通过用户ID
     *
     * @return 特定用户
     */
    User getUserById();

    /**
     * 更新用户信息
     *
     * @param user 用户实例
     * @return 更新是否成功
     */
    int update(User user);

    /**
     * 拆入一个新用户
     *
     * @param user 用户实例
     * @return 插入是否成功
     */
    int insert(User user);

    /**
     * 删除一个用户
     *
     * @param id 用户id
     * @return 删除是否成功
     */
    int delete(int id);
}
 ```
接下来我们只需要去编写配置文件 UserMapper.xml

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.arctic.dao.UserMapper">
    <select id="getUserList" resultType="com.arctic.pojo.User">
        select *
        from mybatis.user;
    </select>

    <select id="getUserById" resultType="com.arctic.pojo.User" parameterType="int">
        select *
        from mybatis.user
        where id = #{id};
    </select>

    <update id="update" parameterType="com.arctic.pojo.User">
        update mybatis.user
        set name = #{name},
            pwd  = #{pwd}
        where id = #{id};
    </update>

    <insert id="insert" parameterType="com.arctic.pojo.User">
        insert into mybatis.user (id, name, pwd)
        values (#{id}, #{name}, #{pwd});
    </insert>

    <delete id="delete" parameterType="int">
        delete
        from mybatis.user
        where id = #{id};
    </delete>
</mapper>
```
编写配置文件时，函数传入的参数值，和实体类具体的值都可以通过#{}取得
编写测试类：
```java
public class UserMapperTest {
    @Test
    public void getUserListTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        List<User> users = userMapper.getUserList();
        for (User user : users) {
            System.out.println(user);
        }
        sqlSession.close();
    }

    @Test
    public void getUserByIdTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        User user = userMapper.getUserById(1);
        System.out.println(user);
        sqlSession.close();
    }

    @Test
    public void updateTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        int res = userMapper.update(new User(1,"ArcticTest","UpdateTest"));
        if (res > 0 ){
            System.out.println("更新成功");
        }
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void insertTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        int res = userMapper.insert(new User(5,"InsertTest","test"));
        if (res > 0 ){
            System.out.println("插入成功");
        }
        sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void deleteTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        int res = userMapper.delete(5);
        if (res > 0 ){
            System.out.println("删除成功");
        }
        sqlSession.commit();
        sqlSession.close();
    }
}
```
我们要注意：**增删改属于事务需要提交 sqlSession.commit**
测试结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210122175914144.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210122175914141.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210122175914115.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70#pic_center)

## CRUD中巧妙的方法 （但是不适合调试）
使用map作为参数时，MyBatis会自动取值，这样针对数据库表字段较多的情况或者参数过多我们就可以考虑使用map作为参数。
 在UserMapper中添加一个方法。
 ```java
     /**
     * 更新用户
     * 
     * @param map map参数
     * @return 更新是否成功
     */
    int updateUser(Map<String,Object> map);
 ```
编写配置xml：
```xml
    <update id="updateUser" parameterType="map">
        update mybatis.user
        set name = #{username}
        where id = #{id};
    </update>
```
编写测试类，注意Map的应用：
```java
    @Test
    public void updateUserTest(){
        SqlSession sqlSession = MyBatisUtil.getSqlSession();
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        Map<String,Object> map = new HashMap<>();
        map.put("username","TestMap");
        map.put("id",4);
        int res = userMapper.updateUser(map);
        if (res > 0 ){
            System.out.println("更新成功");
        }
        sqlSession.commit();
        sqlSession.close();
    }
}
```
这里要注意map中的键值对要和配置类中的名相同。

## 模糊查询
1. Java代码执行的时候，传递通配符 % %

   ```java
   List<User> userList = mapper.getUserLike("%李%");
   ```

2. 在sql拼接中使用通配符！

   ```java
   select * from mybatis.user where name like "%"#{value}"%"
   ```

## 配置文件
MyBatis 的配置文件包含了会深深影响 MyBatis 行为的设置和属性信息。 配置文档的顶层结构如下：

 - configuration（配置）
 -  properties（属性）
 -  settings（设置）
 -  typeAliases（类型别名）
 - typeHandlers（类型处理器）
 -  objectFactory（对象工厂）
 -  plugins（插件）
 - environments（环境配置）
    environment（环境变量） transactionManager（事务管理器) dataSource（数据源)
  - databaseIdProvider（数据库厂商标识） 
  - mappers（映射器）

这是来自mybatis官方的配置文件结构
mybatis配置文件会影响整个mybatis框架的运行和属性

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
	<!-- 环境配置 default设置当前使用哪个环境配置 -->
    <environments default="development">
    	<!-- 环境配置 id：环境的标识-->
        <environment id="development">
       		<!-- 事务管理器 默认jdbc-->
            <transactionManager type="JDBC"/>
            <!-- 数据源 默认是数据池连接方式-->
            <dataSource type="POOLED">
                <property name="driver" value="com.mysql.jdbc.Driver"/>
                <property name="url" value="jdbc:mysql://localhost:3306/mybatis?serverTimezone=GMT%2B8&amp;useUnicode=true&amp;characterEncode=UTF-8"/>
                <property name="username" value="root"/>
                <property name="password" value="ssf123123"/>
            </dataSource>
        </environment>
    </environments>
    <!-- mapper映射器-->
    <mappers>
        <mapper resource="com/arctic/dao/UserMapper.xml"/>
    </mappers>
</configuration>
```

## 环境配置（environments）
MyBatis 可以配置成适应多种环境

**不过要记住：尽管可以配置多个环境，但每个 SqlSessionFactory 实例只能选择一种环境。**

学会使用配置多套运行环境！

Mybatis默认的事务管理器就是 JDBC  ， 连接池 ： POOLED
属性（properties）
这些属性可以在外部进行配置，并可以进行动态替换。你既可以在典型的 Java 属性文件中配置这些属性，也可以在 properties 元素的子元素中设置。例如：
```xml
<properties resource="org/mybatis/example/config.properties">
  <property name="username" value="dev_user"/>
  <property name="password" value="F2Fa3!33TYyg"/>
</properties>
```
设置好的属性可以在整个配置文件中用来替换需要动态配置的属性值。比如:

```xml
<dataSource type="POOLED">
  <property name="driver" value="${driver}"/>
  <property name="url" value="${url}"/>
  <property name="username" value="${username}"/>
  <property name="password" value="${password}"/>
</dataSource>
```

这个例子中的 username 和 password 将会由 properties 元素中设置的相应值来替换。 driver 和 url 属性将会由 config.properties 文件中对应的值来替换。这样就为配置提供了诸多灵活选择。
这是来自官方文档中的例子这告诉我们属性的值是可以动态替换的。
我们现在resources文件夹下新建db.properties
```xml
driver=com.mysql.jdbc.Driver
url=jdbc:mysql://localhost:3306/mybatis?serverTimezone=GMT%2B8&amp;useUnicode=true&amp;characterEncode=UTF-8
username=root
password=ssf123123
```
然后修改mybatis-config.xml文件
```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
    <properties resource="db.properties"/>
    <environments default="development">
        <environment id="development">
            <transactionManager type="JDBC"/>
            <dataSource type="POOLED">
                <property name="driver" value="${driver}"/>
                <property name="url"
                          value="${url}"/>
                <property name="username" value="${username}"/>
                <property name="password" value="${password}"/>
            </dataSource>
        </environment>
    </environments>
    <mappers>
        <mapper resource="com/arctic/dao/UserMapper.xml"/>
    </mappers>
</configuration>
```
这里需要注意配置文件标签的顺序
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210126113814813.png#pic_center)
注意：
- 可以直接引入外部文件
- 可以在其中增加一些属性配置
- 如果两个文件有同一个字段，优先使用外部配置文件的！
## 类型别名（typeAliases）

- 类型别名是为 Java 类型设置一个短的名字。‘
- 存在的意义仅在于用来减少类完全限定名的冗余。

```xml
    <!--可以给实体类起别名-->
    <typeAliases>
        <typeAlias type="com.kuang.pojo.User" alias="User"/>
    </typeAliases>
```

也可以指定一个包名，MyBatis 会在包名下面搜索需要的 Java Bean，比如：

扫描实体类的包，它的默认别名就为这个类的 类名，首字母小写！

```xml
<!--可以给实体类起别名-->
<typeAliases>
    <package name="com.kuang.pojo"/>
</typeAliases>
```



在实体类比较少的时候，使用第一种方式。

如果实体类十分多，建议使用第二种。

第一种可以DIY别名，第二种则·不行·，如果非要改，需要在实体上增加注解

```java
@Alias("user")
public class User {}
```
## 设置
这是 MyBatis 中极为重要的调整设置，它们会改变 MyBatis 的运行时行为。 

## 其他配置

- [typeHandlers（类型处理器）](https://mybatis.org/mybatis-3/zh/configuration.html#typeHandlers)
- [objectFactory（对象工厂）](https://mybatis.org/mybatis-3/zh/configuration.html#objectFactory)
- plugins插件
  - mybatis-generator-core
  - mybatis-plus
  - 通用mapper

## 映射器（mappers）

MapperRegistry：注册绑定我们的Mapper文件；

方式一： 【推荐使用】

```xml
<!--每一个Mapper.XML都需要在Mybatis核心配置文件中注册！-->
<mappers>
    <mapper resource="com/kuang/dao/UserMapper.xml"/>
</mappers>
```

方式二：使用class文件绑定注册

```xml
<!--每一个Mapper.XML都需要在Mybatis核心配置文件中注册！-->
<mappers>
    <mapper class="com.kuang.dao.UserMapper"/>
</mappers>
```

注意点：

- 接口和他的Mapper配置文件必须同名！
- 接口和他的Mapper配置文件必须在同一个包下！



方式三：使用扫描包进行注入绑定

```xml
<!--每一个Mapper.XML都需要在Mybatis核心配置文件中注册！-->
<mappers>
    <package name="com.kuang.dao"/>
</mappers>
```

注意点：

- 接口和他的Mapper配置文件必须同名！
- 接口和他的Mapper配置文件必须在同一个包下！

## 生命周期和作用域

生命周期，和作用域，是至关重要的，因为错误的使用会导致非常严重的**并发问题**。

**SqlSessionFactoryBuilder：**

- 一旦创建了 SqlSessionFactory，就不再需要它了
- 局部变量

**SqlSessionFactory：**

- 说白了就是可以想象为 ：数据库连接池
- SqlSessionFactory 一旦被创建就应该在应用的运行期间一直存在，**没有任何理由丢弃它或重新创建另一个实例。** 
- 因此 SqlSessionFactory 的最佳作用域是应用作用域。 
- 最简单的就是使用**单例模式**或者静态单例模式。

**SqlSession**

- 连接到连接池的一个请求！
- SqlSession 的实例不是线程安全的，因此是不能被共享的，所以它的最佳的作用域是请求或方法作用域。
- 用完之后需要赶紧关闭，否则资源被占用！


这里面的每一个Mapper，就代表一个具体的业务！