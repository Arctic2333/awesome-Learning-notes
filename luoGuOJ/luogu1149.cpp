//思路：打表 数据不大时 时间复杂度o（1） 线性搜索o（n）
#include <iostream>

using namespace std;

int a[10] = {
    6,
    2,
    5,
    5,
    4,
    5,
    6,
    3,
    7,
    6
};
int temp[2001] = {
    0
};

void meter() {
    for (int i = 1; i <= 2000; i++) {
        int j = i;
        while (j >= 1) {
            temp[i] = temp[i] + a[j % 10];
            j = j / 10;
        }
    }
}

int main() {
    temp[0] = 6;
    int n;
    cin >> n;
    int ans = 0;
    meter();
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            if ((temp[i] + temp[j] + temp[i + j] + 4) == n) {
                ans++;
            }
    cout << ans;
    return 0;
}

/*题目描述
给你n根火柴棍，你可以拼出多少个形如“A+B=CA+B=C”的等式？等式中的AA、BB、CC是用火柴棍拼出的整数（若该数非零，则最高位不能是00）。用火柴棍拼数字0-90−9的拼法如图所示：



注意：

加号与等号各自需要两根火柴棍

如果A≠BA 

​	
 =B，则A+B=CA+B=C与B+A=CB+A=C视为不同的等式(A,B,C>=0A,B,C>=0)

nn根火柴棍必须全部用上

输入格式
一个整数n(n<=24)n(n<=24)。

输出格式
一个整数，能拼成的不同等式的数目。

输入输出样例
输入 #1 复制
14
输出 #1 复制
2
输入 #2 复制
18
输出 #2 复制
9
说明/提示
【输入输出样例1解释】

22个等式为0+1=10+1=1和1+0=11+0=1。

【输入输出样例2解释】

99个等式为：

0+4=4
0+11=11
1+10=11
2+2=4
2+7=9
4+0=4
7+2=9
10+1=11
11+0=11
题目：https://www.luogu.com.cn/problem/P1149
*/