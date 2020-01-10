/*对于一个递归函数w(a,b,c)w(a,b,c)

如果a \le 0a≤0 or b \le 0b≤0 or c \le 0c≤0就返回值11.
如果a>20a>20 or b>20b>20 or c>20c>20就返回w(20,20,20)w(20,20,20)
如果a<ba<b并且b<cb<c 就返回w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)w(a,b,c−1)+w(a,b−1,c−1)−w(a,b−1,c)
其它的情况就返回w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)w(a−1,b,c)+w(a−1,b−1,c)+w(a−1,b,c−1)−w(a−1,b−1,c−1)
这是个简单的递归函数，但实现起来可能会有些问题。当a,b,ca,b,c均为15时，调用的次数将非常的多。你要想个办法才行.

/*  比如 w(30,-1,0)w(30,−1,0)既满足条件1又满足条件2

这种时候我们就按最上面的条件来算

所以答案为1

*/

/*输入格式
会有若干行。

并以-1,-1,-1−1,−1,−1结束。

保证输入的数在[-9223372036854775808,9223372036854775807][−9223372036854775808,9223372036854775807]之间，并且是整数。

输出格式
输出若干行，每一行格式：

w(a, b, c) = ans

注意空格。

输入输出样例
输入 #1 复制
1 1 1
2 2 2
-1 -1 -1
输出 #1 复制
w(1, 1, 1) = 2
w(2, 2, 2) = 4



说明/提示
记忆化搜索


*/
#include <iostream>

#include <stdio.h>

#include <cstring>

using std::cin;
using std::cout;
using std::endl;


long long me[30][30][30];
long long w(long long a, long long b, long long c) {

    if (a <= 0 || b <= 0 || c <= 0) return 1;
    else if (me[a][b][c] != 0) return me[a][b][c];
    else if (a > 20 || b > 20 || c > 20) me[a][b][c] = w(20, 20, 20);
    else if (a < b && b < c) me[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else me[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return me[a][b][c];
}

int main() {
    long long a, b, c;
    while (scanf("%lld%lld%lld", & a, & b, & c) == 3) {
        memset(me, 0, sizeof(me));
        if (a == (-1) && b == (-1) && c == (-1)) break;
        printf("w(%lld, %lld, %lld) = ", a, b, c);
        if (a > 20) a = 21;
        if (b > 20) b = 21;
        if (c > 20) c = 21;
        printf("%lld\n", w(a, b, c));
    }
}