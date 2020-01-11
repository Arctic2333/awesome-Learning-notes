/*
 题目描述
现在请你编一个程序验证哥德巴赫猜想。

先给出一个奇数n，要求输出3个质数，这3个质数之和等于输入的奇数。

输入格式
仅有一行，包含一个正奇数n，其中9<n<20000

输出格式
仅有一行，输出3个质数，这3个质数之和等于输入的奇数。相邻两个质数之间用一个空格隔开，最后一个质数后面没有空格。如果表示方法不唯一，请输出第一个质数最小的方案，如果第一个质数最小的方案不唯一，请输出第一个质数最小的同时，第二个质数最小的方案。

输入输出样例
输入 #1 复制
2009
输出 #1 复制
3 3 2003

暴力》》》》》判断素数  数据较弱 如果是大数据可以先筛一下素数
题目来源：https://www.luogu.com.cn/problem/P1579
*/
#include <stdio.h>

#include <math.h>

bool isPrimer(int x) {
    if (x < 2) return 0;
    if (x == 2) return 1;
    if (x > 2) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0)
                return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", & n);
    int x1, x2, x3;
    int i, j;
    int flag = 0;
    for (i = 2; i <= n - 4; i++) {
        if (flag == 0) {
            for (j = 2; j <= n - 4 - i; j++) {
                x1 = i;
                x2 = j;
                x3 = n - i - j;
                if (isPrimer(x1) && isPrimer(x2) && isPrimer(x3)) {
                    printf("%d %d %d", x1, x2, x3);
                    flag = 1;
                    break;
                } else {
                    continue;
                }
            }
        }
    }
    return 0;
}