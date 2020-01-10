/*题目描述
我们要求找出具有下列性质数的个数(包含输入的自然数nn):

先输入一个自然数nn(n \le 1000n≤1000),然后对此自然数按照如下方法进行处理:

不作任何处理;

在它的左边加上一个自然数,但该自然数不能超过原数的一半;

加上数后,继续按此规则进行处理,直到不能再加自然数为止.

输入格式
11个自然数nn(n \le 1000n≤1000)

输出格式
11个整数，表示具有该性质数的个数。

输入输出样例
输入 #1 复制
6
输出 #1 复制
6
说明/提示
满足条件的数为

6，16，26，126，36，136

题目来自：https://www.luogu.com.cn/problem/P1028

思路：手动递推出了规律  先是使用递归来写严重超时
#include <stdio.h>

int num(int i){
	if(i == 1) 
		return 1;
	else{
		if( (i&1) ==0  ){
			return num(i-1) + num(i/2);
		}
		else{
			return num(i-1);
		}
	}
}

int main (){
	int n;
	scanf("%d",&n);
	int j = num(n);
	printf("%d",j);
	return 0;
}
*/
#include <stdio.h>

int main(){
	int n;
	int f[1005];
	f[1] = 1;
	f[0] = 0;
	scanf("%d",&n);
	for(int i = 2;i<=n;i++)
		f[i] = ((i&1)?0:1)*f[ i>>1 ] + f[i-1];    //空间复杂度为o（n）  递推
	printf("%d",f[n]);
	return 0;
}