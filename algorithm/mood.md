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

**int a[15] = {0};**
**��������ѵ�һ����ʼ��ֵ(������0)��������ĵ�һ��Ԫ�أ�Ȼ����Ĭ��ֵ0���������Ԫ�ء����û�и�����ʼֵ������������ȥ����ʼ���������������ķ�ʽ�ô�����Ӹ�Ч��**

### **����ģ�壺**

```c++
void search(int t)
{
    if(�����������)
    {
        �����;
    }
    else
    {
        for(int i=1;i<=���Է�����;i++)
            if(�����һ����������)
            {
                Ϊ��һ����������Ҫ��״̬���ϱ��;
                search(t+1);
                �ָ�������ǰ��״̬;//Ҳ����˵��{����һ��}
            }
    }
}
```

����ģ���м����ط���Ҫע�⣺
1.��һ��if�Ƿ����������������ڶ���if�Ƿ��Ͻ�һ��������������

����ģ���м����ط���Ҫע�⣺
1.��һ��if�Ƿ����������������ڶ���if�Ƿ��Ͻ�һ��������������

2.��һ������ʱ������ʹ��return search(t+1)��ֱ��search(t+1);�����ֿ��ܻ�ע�ⲻ������ؼ��ĵط���������ÿ��д�겻֪��Ϊʲôֻ�õ�һ���𰸾ͷ����������ˣ�

3.forѭ��֮���if�����Ƕ��;

4.forѭ���߽磬���磺

1>�������ĸ�����ô�߽�϶�����4����������3������Ϊ��0��ʼ�ģ�

2>��������Ҫ����1��20����ô�߽����20��

������x+y��ֵ�Ǹ��Խ��ߣ���x-y����ֵ�����Խ���  �м��� ���� �м�����һ����ֵ

### �����������

![](https://img-blog.csdnimg.cn/20200327151252767.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

### dp 0-1��ֵ���� ���ӣ�

![](https://img-blog.csdnimg.cn/20200327151240701.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

```c++
for(int i = 1; i <= m; i++){  // �������
    for(int j = n; j >= c[i];j--){  // ����ֵ
      dp[j] = max(dp[j],dp[j-c[i]]+c[i]*v[i]);
    }
  }
```

### dp ������

dp װ�� ������Ǽ�ֵ

```c++
for(int i = 1; i <= m; i++){
    for(int j = n; j >= c[i];j--){
      dp[j] += dp[j-c[i]]
    }
  }
```

### dp ��ȫ����

```c++
 for (int i = 1; i <= m; i++) {  // �������
    for (int j = c[i]; j <= t; j++) {  //��ǰ�������    ���µ�����ֵ��
      dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    }
  }
```

### dp���鱳�� :ÿ���dp�����ˢ��ֻ��һ�Σ�Ҳ�������ھ�����

![](https://img-blog.csdnimg.cn/2020032715121199.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTUwODkw,size_16,color_FFFFFF,t_70)

```c++
for (int i = 1; i <= N; i++) {

  for (int j = m; j >= 0; j--) {

   for (int k = tol[i-1]+1; k <= tol[i]+tol[i-1]; k++) {

?    if(j-c[k]>=0)

?    dp[j] = max(dp[j], dp[j - c[k]] +v[k]);

   }

  }

 }
```

```cpp
for ���е���k
    for v=V..0
        for ���е�i������k
������������f[v]=max{f[v],f[v-w[i]]+c[i]}
```

ע�����������ѭ����˳�򣬡�for v=V..0����һ��ѭ�������ڡ�for ���е�i������k��֮�⡣�������ܱ�֤ÿһ���ڵ���Ʒ���ֻ��һ���ᱻ��ӵ������С�

### Floyd

```c++
for(int k=1;k<=n;k++)//���ӵ�
    for(int i=1;i<=n;i++)//���
    for(int j=1;j<=n;j++){//�յ�
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    }
```

