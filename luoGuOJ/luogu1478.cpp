/*题目描述
又是一年秋季时，陶陶家的苹果树结了 nn 个果子。陶陶又跑去摘苹果，这次他有一个 aa 公分的椅子。当他手够不着时，
他会站到椅子上再试试。

这次与 NOIp2005 普及组第一题不同的是：陶陶之前搬凳子，力气只剩下 ss 了。当然，每次摘苹果时都要用一定的力气。陶陶想知道在 
s<0s<0 之前最多能摘到多少个苹果。

现在已知 nn 个苹果到达地上的高度 x_ix i，椅子的高度 aa，陶陶手伸直的最大长度 bb，陶陶所剩的力气 ss，陶陶摘一个苹果需要的力气 y_iy i
，求陶陶最多能摘到多少个苹果。

输入格式
第 11 行：两个数 苹果数 nn，力气 ss。

第 22 行：两个数 椅子的高度 aa，陶陶手伸直的最大长度 bb。

第 33 行~第 3+n-13+n−1 行：每行两个数 苹果高度 x_ix i	，摘这个苹果需要的力气 y_iyi。

输出格式
只有一个整数，表示陶陶最多能摘到的苹果数。

输入输出样例
输入 #1 复制
8 15
20 130
120 3
150 2
110 7
180 1
50 8
200 0
140 3
120 2
输出 #1 复制
4

贪心算法  力气消耗少的先拿
*/
#include <bits/stdc++.h>

using std::cin;
using std::cout;
struct apple {
    int x;
    int y;
} app[5005];

int main() {
    int n, s, a, b;
    int ans = 0;
    cin >> n >> s >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> app[i].x >> app[i].y;
    }
    apple temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            if (app[j].y > app[j + 1].y) {
                temp = app[j];
                app[j] = app[j + 1];
                app[j + 1] = temp;
            }
        }

    for (int i = 0; i < n; i++) {
        if (app[i].y > s) {
            break;
        }
        if (app[i].x <= a + b) {
            ans++;
            s = s - app[i].y;
        }
    }
    cout << ans;
    return 0;
}