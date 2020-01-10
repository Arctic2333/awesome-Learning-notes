// Copyright 2020 Arctic2333
/*
 *题目描述
 *蒟蒻虽然忘记密码，但他还记得密码是由一个字符串组成。密码是由原文字符串（由不超过 50 个小写字母组成）中每个字母向后移动 nn 位形成的。z 的下一个字母是 a，如此循环。他现在找到了移动前的原文字符串及 nn，请你求出密码。
 *
 *输入格式
 *第一行：n。第二行：未移动前的一串字母
 *
 *输出格式
 *一行，是此蒟蒻的密码
 *来源：https://www.luogu.com.cn/problem/P1914
 * 思路：一个字符串读原文 一个字符串做abcd等的容器
 * （原文字符 -‘a’ + n）% 26 数学思路 
 */
#include <string>

#include <iostream>

using std::cin;
using std::cout;  // 尽量避免使用所有的命名空间
using std::string;

int main() {
    string str;
    int n;
    cin >> n;
    cin >> str;
    string word = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < str.length(); i++) {
        cout << word[(str[i] - 'a' + n) % 26];
    }
}