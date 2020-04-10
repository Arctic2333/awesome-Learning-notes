```c++
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;
```

### 读入优化：

```c++
template <class T> void read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f |= (ch == '-');
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
```

**int a[15] = {0};**
**编译器会把第一个初始化值(这里是0)赋给数组的第一个元素，然后用默认值0赋给其余的元素。如果没有给出初始值，编译器不会去做初始化工作。这样简洁的方式让代码更加高效。**

### **深搜模板：**

```c++
void search(int t)
{
    if(满足输出条件)
    {
        输出解;
    }
    else
    {
        for(int i=1;i<=尝试方法数;i++)
            if(满足进一步搜索条件)
            {
                为进一步搜索所需要的状态打上标记;
                search(t+1);
                恢复到打标记前的状态;//也就是说的{回溯一步}
            }
    }
}
```

整个模板有几个地方需要注意：
1.第一个if是符合输出解的条件，第二个if是符合进一步搜索的条件；

整个模板有几个地方需要注意：
1.第一个if是符合输出解的条件，第二个if是符合进一步搜索的条件；

2.下一步搜索时，不是使用return search(t+1)，直接search(t+1);（新手可能会注意不到这个关键的地方，以至于每次写完不知道为什么只得到一个答案就返回主程序了）

3.for循环之后的if可以是多个;

4.for循环边界，例如：

1>方向是四个，那么边界肯定就是4；（帖主用3，是因为从0开始的）

2>素数环需要尝试1至20，那么边界就是20；

格子中x+y的值是副对角线，（x-y）的值是主对角线  行减列 或者 行加列是一个定值

### 广度优先搜索

![](https://img-blog.csdnimg.cn/20200327151252767.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### dp 0-1价值背包 板子：

![](https://img-blog.csdnimg.cn/20200327151240701.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

```c++
for(int i = 1; i <= m; i++){  // 种类相关
    for(int j = n; j >= c[i];j--){  // 最大价值
      dp[j] = max(dp[j],dp[j-c[i]]+c[i]*v[i]);
    }
  }
```

### dp 方案数   一定要将dp[0] = 1;  这个是没有价值的

```c++
for(int i = 1; i <= m; i++){
    for(int j = n; j >= c[i];j--){
      dp[j] += dp[j-c[i]]
    }
  }
```

```c++
for (int i = 1; i <= n; i++) {
    int v, w;
    scanf("%d%d", &v, &w);
    for (int j = m; j >= v; j--) {
      int value = f[j - v] + w;
      if (value > f[j]) {
        f[j] = value;
        cnt[j] = cnt[j - v];
      } else if (value == f[j]) {
        cnt[j] = (cnt[j] + cnt[j - v]) % mod;
      }
    }
  }
```



### dp 完全背包

```c++
 for (int i = 1; i <= m; i++) {  // 种类相关
    for (int j = c[i]; j <= t; j++) {  //从前往后更新    更新到最大价值处
      dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    }
  }
```

### dp分组背包 :每组对dp数组的刷新只能一次，也就是组内竞争。

![](https://img-blog.csdnimg.cn/2020032715121199.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

```c++
for (int i = 1; i <= N; i++) {

  for (int j = m; j >= 0; j--) {

   for (int k = tol[i-1]+1; k <= tol[i]+tol[i-1]; k++) {

    if(j-c[k]>=0)

    dp[j] = max(dp[j], dp[j - c[k]] +v[k]);

   }

  }

 }
```

```cpp
for 所有的组k
    for v=V..0
        for 所有的i属于组k
　　　　　　f[v]=max{f[v],f[v-w[i]]+c[i]}
```

注意这里的三层循环的顺序，“for v=V..0”这一层循环必须在“for 所有的i属于组k”之外。这样才能保证每一组内的物品最多只有一个会被添加到背包中。

### Floyd

```c++
for(int k=1;k<=n;k++)//连接点
    for(int i=1;i<=n;i++)//起点
    for(int j=1;j<=n;j++){//终点
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    }
```

## 技巧：二维压一维。

不知道大家想到上面的计算方向以后，有没有跟我当初一样，为排序而发愁呢？
STL的sort函数要求传入一个连续的内存区间，但是数组开成二维以后，却难以保证想要排序的区域是连续的。也就是说

```cpp
    sort(a+1, a+r*c+1);
```

会哇（*WA*）。怎么办呢？？？
答案是：把数组开成**一维**的！
对于这样的一5×5格子

|      |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  1   |      |      |      |      |      |
|  2   |      |      |      |      |      |
|  3   |      |      |      |      |      |
|  4   |      |      |      |      |      |
|  5   |      |      |      |      |      |

对它的每个格子进行编号，使每个格子的编号唯一。相信最简单的方法应该就是这样了吧：

|      |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  1   |  1   |  2   |  3   |  4   |  5   |
|  2   |  6   |  7   |  8   |  9   |  10  |
|  3   |  11  |  12  |  13  |  14  |  15  |
|  4   |  16  |  17  |  18  |  19  |  20  |
|  5   |  21  |  22  |  23  |  24  |  25  |

那么，按照这种思路，题目样例就可以被存成这样：

| *i*  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  10  |  11  |  12  |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |  21  |  22  |  23  |  24  |  25  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| a_i  |  1   |  2   |  3   |  4   |  5   |  16  |  17  |  18  |  19  |  6   |  15  |  24  |  25  |  20  |  7   |  14  |  23  |  22  |  21  |  8   |  13  |  12  |  11  |  10  |  9   |

可是，向上下左右格子的编号又分别是什么呢？？
由**观察法**易得：
设格子一共有R*R*行C*C*列，当前已知的格子编号是X*X*，那么其周边的格子编号如下（**不考虑边界**）:

| X*?*C*?1  | X*?*C* | X*?*C+1 |
| :-------: | :----: | :-----: |
|   *X*?1   |  *X*   |  *X*+1  |
| *X*+*C*?1 | X*+*C  | X*+*C+1 |

可是问题来了：**如何考虑边界？？？**
很简单：

- 当且仅当X*?*C*≤0时，X*位于最上一行；
- 当且仅当X*+*C*>*R*×*C*时，X*位于最下一行；
- 当且仅当X**m**o**d**C*=0时，X*位于最右一行；
- 当且仅当(*X*?1)*m**o**d*C*=0时，X*位于最左一行。

### 状态压缩dp：用一个二进制数记录状态

di：记录状态

假如 有 3个点 1 和 3 被	访问过

?     123

di=101

dp [ di的可能]  [点的数目]

```c++
void dfs(int p,int cur,double s,int bi){
    if(s > ans){
        return;
    }
    if(p == n){
        ans = min (ans,s);
        return;
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            int t = bi + (1<<(i-1))；
            if(dp[t][i]!=0 && dp[t][i] <= s+dis(cur,i))
                continue;
            vis[i] = 1;
            dp[t][i] = s + dis(cur,i);
            dfs(p+1,i,dp[t][i],t);
            vis[i] = 0;
        }
    }
}
```

