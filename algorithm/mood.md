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

### �����Ż���

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

### dp ������   һ��Ҫ��dp[0] = 1;  �����û�м�ֵ��

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

    if(j-c[k]>=0)

    dp[j] = max(dp[j], dp[j - c[k]] +v[k]);

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

ע�����������ѭ����˳�򣬡�for v=V..0����һ��ѭ�������ڡ�for ���е�i������k��֮�⡣�������ܱ�֤ÿһ���ڵ���Ʒ���ֻ��һ���ᱻ���ӵ������С�

### Floyd

```c++
for(int k=1;k<=n;k++)//���ӵ�
    for(int i=1;i<=n;i++)//���
    for(int j=1;j<=n;j++){//�յ�
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    }
```

## ���ɣ���άѹһά��

��֪������뵽����ļ��㷽���Ժ���û�и��ҵ���һ����Ϊ����������أ�
STL��sort����Ҫ����һ���������ڴ����䣬�������鿪�ɶ�ά�Ժ�ȴ���Ա�֤��Ҫ����������������ġ�Ҳ����˵

```cpp
    sort(a+1, a+r*c+1);
```

���ۣ�*WA*������ô���أ�����
���ǣ������鿪��**һά**�ģ�
����������һ5��5����

|      |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  1   |      |      |      |      |      |
|  2   |      |      |      |      |      |
|  3   |      |      |      |      |      |
|  4   |      |      |      |      |      |
|  5   |      |      |      |      |      |

������ÿ�����ӽ��б�ţ�ʹÿ�����ӵı��Ψһ��������򵥵ķ���Ӧ�þ��������˰ɣ�

|      |  1   |  2   |  3   |  4   |  5   |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  1   |  1   |  2   |  3   |  4   |  5   |
|  2   |  6   |  7   |  8   |  9   |  10  |
|  3   |  11  |  12  |  13  |  14  |  15  |
|  4   |  16  |  17  |  18  |  19  |  20  |
|  5   |  21  |  22  |  23  |  24  |  25  |

��ô����������˼·����Ŀ�����Ϳ��Ա����������

| *i*  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  10  |  11  |  12  |  13  |  14  |  15  |  16  |  17  |  18  |  19  |  20  |  21  |  22  |  23  |  24  |  25  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| a_i  |  1   |  2   |  3   |  4   |  5   |  16  |  17  |  18  |  19  |  6   |  15  |  24  |  25  |  20  |  7   |  14  |  23  |  22  |  21  |  8   |  13  |  12  |  11  |  10  |  9   |

���ǣ����������Ҹ��ӵı���ֱַ���ʲô�أ���
��**�۲취**�׵ã�
�����һ����R*R*��C*C*�У���ǰ��֪�ĸ��ӱ����X*X*����ô���ܱߵĸ��ӱ�����£�**�����Ǳ߽�**��:

| X*?*C*?1  | X*?*C* | X*?*C+1 |
| :-------: | :----: | :-----: |
|   *X*?1   |  *X*   |  *X*+1  |
| *X*+*C*?1 | X*+*C  | X*+*C+1 |

�����������ˣ�**��ο��Ǳ߽磿����**
�ܼ򵥣�

- ���ҽ���X*?*C*��0ʱ��X*λ������һ�У�
- ���ҽ���X*+*C*>*R*��*C*ʱ��X*λ������һ�У�
- ���ҽ���X**m**o**d**C*=0ʱ��X*λ������һ�У�
- ���ҽ���(*X*?1)*m**o**d*C*=0ʱ��X*λ������һ�С�

### ״̬ѹ��dp����һ������������¼״̬

di����¼״̬

���� �� 3���� 1 �� 3 ��	���ʹ�

?     123

di=101

dp [ di�Ŀ���]  [�����Ŀ]

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
            int t = bi + (1<<(i-1))��
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

![](https://img-blog.csdnimg.cn/20200412143221467.PNG)



## C++ string ����substr��ʹ�÷���

```c++
#include<string>
using namespace std;
int main()
{
    string x="Hello_World";
    /*Ĭ�Ͻ�ȡ��0��npos.����ԭ��Ϊstring substr(_off=0,_count=npos);nposһ���ʾΪstring���в����ڵ�λ��,_off��ʾ�ַ����Ŀ�ʼλ�ã�_count��ȡ���ַ�����Ŀ*/
    cout<<x.substr()<<endl;
    cout<<x.substr(5)<<endl;//��ȡx[5]����β����npos.����ԭ��Ϊstring substr(_off,_count=npos)
    cout<<x.substr(0,5)<<endl;//��x[0]Ϊʼ������ȡ5λ������x[0]��������ԭ��string substr(_off,_count)
    /*
    ��ע��
    ָ���Ľ�ȡ���ȼ���ʼλ�ü�_off+_count>Դ�ַ����ĳ��ȣ������ַ�����������Դ�ַ����Ľ�β
    */
}
```

### scanf("%1d",&a); ��ʽ������ һ��ֻ����һλ��