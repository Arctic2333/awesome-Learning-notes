/*题目描述
给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例2）。

输入格式
一个整数 NN

输出格式
一个整数，表示反转后的新数。

输入输出样例
输入 #1 复制
123
输出 #1 复制
321
输入 #2 复制
-380
输出 #2 复制
-83
说明/提示
数据范围

-1,000,000,000≤N≤1,000,000,000 −1,000,000,000≤N≤1,000,000,000。

noip2011普及组第一题*/
#include <iostream>

#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
    string str1;
    cin >> str1;
    int i = str1.length() - 1;
    if (str1[0] == '-') {
        while (str1[i] == '0')
            i--;
        cout << str1[0];
        while (i >= 1) {
            cout << str1[i];
            i--;
        }
    } else if (str1 == "0") {
        cout << "0";
    } else {
        while (str1[i] == '0')
            i--;
        while (i >= 0) {
            cout << str1[i];
            i--;
        }
    }
    return 0;
}