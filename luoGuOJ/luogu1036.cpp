/*题目描述
已知 nn 个整数 x_1,x_2,…,x_nx 
1
​	
 ,x 
2
​	
 ,…,x 
n
​	
 ，以及11个整数kk(k<nk<n)。从nn个整数中任选kk个整数相加，可分别得到一系列的和。例如当n=4,k=3n=4,k=3,44个整数分别为3,7,12,193,7,12,19时，可得全部的组合与它们的和为：

3+7+12=223+7+12=22

3+7+19=293+7+19=29

7+12+19=387+12+19=38

3+12+19=343+12+19=34。

现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：3+7+19=293+7+19=29。

输入格式
键盘输入，格式为：

n,kn,k(1 \le n \le 20,k<n1≤n≤20,k<n)

x_1,x_2,…,x_n (1 \le x_i \le 5000000)x 1,x2 ,…,xn
​	
 (1≤xi≤5000000)

输出格式
屏幕输出，格式为： 11个整数（满足条件的种数）。

输入输出样例
输入 #1 复制
4 3
3 7 12 19
输出 #1 复制
1
题目来源：https://www.luogu.com.cn/problem/P1036
思路：排列组合选数，并把选出的数存在一个数组里
最大的收获 是：排列组合的c语言实现
*/
#include <iostream>
#include <cmath>

using namespace std;
int t =0,c[100000];
bool Isprime(int b){
	if(b==2)
		return true;
	else if (b<2)
		return false;
	else
		for(int i=2; i<=sqrt(b) ;i++)
			if(b%i==0)
				return false;
	return true;
}
void combine(int n,int m,int a[],int b[],const int M){
	for (int j =n;j>=m;j--){
		b[m-1] = j-1;
		if(m>1)
			combine(j-1,m-1,a,b,M);
		else{
			for(int i = M-1;i>=0;i--) 
				c[t]+=a[b[i]];
				t++;
		}
	}
}

int main (){
	int n,k;
	int a[30],b[30];
	cin >> n >> k;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	const int M = k;
	combine(n,k,a,b,M);
	int ans =0;
	for(int i=0;i<t;i++){
		if(Isprime(c[i]))
			ans++;
	}
    cout << ans;
	return 0;
}