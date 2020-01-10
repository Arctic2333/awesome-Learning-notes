/*题目描述
因为 151 既是一个质数又是一个回文数（从左到右和从右到左是看一样的），所以 151 是回文质数。

写一个程序来找出范围 [a,b] (5 \le a < b \le 100,000,000)[a,b](5≤a<b≤100,000,000)( 一亿)间的所有回文质数。

输入格式
第 1 行: 二个整数 a 和 b .

输出格式
输出一个回文质数的列表，一行一个。

输入输出样例
输入 #1 复制
5 500
输出 #1 复制
5
7
11
101
131
151
181
191
313
353
373
383
说明/提示
Hint 1: Generate the palindromes and see if they are prime.

提示 1: 找出所有的回文数再判断它们是不是质数（素数）.

Hint 2: Generate palindromes by combining digits properly. You might need more than one of the loops like below.

提示 2: 要产生正确的回文数，你可能需要几个像下面这样的循环。

题目翻译来自NOCOW。

USACO Training Section 1.5

产生长度为5的回文数:

for (d1 = 1; d1 <= 9; d1+=2) {    // 只有奇数才会是素数
     for (d2 = 0; d2 <= 9; d2++) {
         for (d3 = 0; d3 <= 9; d3++) {
           palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;//(处理回文数...)
         }
     }
 }

 题目来源：https://www.luogu.com.cn/problem/P1217
 思路：先判断是否是回文数 再判断是否是素数
*/
#include <stdio.h>

#include <math.h>

bool isPrimr(int n) {
	if (n == 1)
		return false;
	else if (n == 2)
		return true;
	else {
		for (register int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0)
				return false;
		}
	}
	return true;
}

bool hw(int n) {       //判断回文数，先数字反转然后判断与原数是否相同
	int sum = 0, k = n;
	while (k != 0) {
		sum = sum * 10 + k % 10;
		k /= 10;
	}
	if (sum == n)
		return true;
	else
		return false;
}

int main() {
	int a, b;
	scanf("%d%d", & a, & b);
	if ((a & 1) == 0)     //如果a是偶数一定不是素数，就需要加一！
		a++;			// 后面循环步长为2 可以省下一半的时间
	for (register int i = a; i <= b; i += 2) {
		if (hw(i)) {
			if (isPrimr(i))
				printf("%d\n", i);
		}
	}
	return 0;
}