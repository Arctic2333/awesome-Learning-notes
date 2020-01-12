/*题目描述
将 1, 2,\ldots, 91,2,…,9 共 99 个数分成三组，分别组成三个三位数，且使这三个三位数的比例是 A:B:CA:B:C，试求出所有满足条件的三个三位数，若无解，输出 No!!!。

//感谢黄小U饮品完善题意

输入格式
三个数，A,B,CA,B,C。

输出格式
若干行，每行 33 个数字。按照每行第一个数字升序排列。

输入输出样例
输入 #1 复制
1 2 3
输出 #1 复制
192 384 576
219 438 657
273 546 819
327 654 981

分解数字数字 判断是否重复
题目来源：https://www.luogu.com.cn/problem/P1618
*/
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int a, b, c;
    int i;
    int ans = 0;
    cin >> a >> b >> c;
    for (i = 1; i <= 1000; i++) {
        int com[10] = { 0 };
        int flag = 1;
        int t1 = a * i;
        int t2 = b * i;
        int t3 = c * i;
        if (t1 > 999 || t2 > 999 || t3 > 999) break;
        if (t1 < 100 || t2 < 100 || t3 < 100) continue;
        int x1 = t1;
        int x2 = t2;
        int x3 = t3;
        while (t1 > 0) {
            com[t1 % 10]++;
            t1 /= 10;
        }
        while (t2 > 0) {
            com[t2 % 10]++;
            t2 /= 10;
        }
        while (t3 > 0) {
            com[t3 % 10]++;
            t3 /= 10;
        }
        if (com[0] != 0) continue;
        for (int j = 1; j < 10; j++) {
            if (com[j] != 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            ans++;
            cout << x1 << " " << x2 << " " << x3 << endl;
        }
    }
    if (ans == 0) {
        cout << "No!!!";
    }
}
