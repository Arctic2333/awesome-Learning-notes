/*题目描述
有一次，小鱼要从A处沿直线往右边游，小鱼第一秒可以游7米，从第二秒开始每秒游的距离只有前一秒的98%。有个极其邪恶的猎人在距离A处右边s米的地方，安装了一个隐蔽的探测器，探测器左右x米之内是探测范围。一旦小鱼进入探测器的范围，探测器就会在这一秒结束时把信号传递给那个猎人，猎人在一秒后就要对探测器范围内的水域进行抓捕，这时如果小鱼还在这范围内就危险了。也就是说小鱼一旦进入探测器范围，如果能在下1秒的时间内马上游出探测器的范围，还是安全的。现在给出s和x的数据，请你判断小鱼会不会有危险？如果有危险输出'y'，没有危险输出'n'。

//感谢黄小U饮品完善题意

输入格式
一行内输入两个实数，用空格分隔，表示s和x。均不大于100

输出格式
一行内输出'y'或者'n'表示小鱼是否会有危险。

输入输出样例
输入 #1 复制
14 1
输出 #1 复制
n
题目来源：https://www.luogu.com.cn/problem/P1426
*/
#include <bits/stdc++.h>

using std::cin;
using std::cout;

int main() {
    double s, x;
    double v = 7, total = 0;
    cin >> s >> x;
    while (total <= s - x) {
        total += v;
        v = v * 0.98;
    }
    double c = total - (s - x);
    double d = (s + x) - (s - x) - c;
    if (v > d)
        cout << "n";
    else {
        cout << "y";
    }

}