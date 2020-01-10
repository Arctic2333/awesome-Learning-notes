/*
题目描述
炎热的夏日，KC 非常的不爽。他宁可忍受北极的寒冷，也不愿忍受厦门的夏天。最近，他开始研究天气的变化。他希望用研究的结果预测未来的天气。

经历千辛万苦，他收集了连续 N(1 \leq N \leq 10^6)N(1≤N≤10 
6
 ) 的最高气温数据。

现在，他想知道最高气温一直上升的最长连续天数。

输入格式
第 1 行：一个整数 NN 。1 \leq N \leq 10^61≤N≤10 
6
 

第 2 行：NN个空格隔开的整数，表示连续 NN 天的最高气温。0 \leq0≤ 最高气温 \leq 10^9≤10 
9
  。

输出格式
1 行：一个整数，表示最高气温一直上升的最长连续天数。

输入输出样例
输入 #1 复制
10
1 2 3 2 4 5 6 8 5 9
输出 #1 复制
5

题目：https://www.luogu.com.cn/problem/P1567

思路：还是使用集合减小使用的空间，反向迭代器 取最后一个元素
*/
#include <iostream>
#include <set>

using namespace std;
int a[1000000];
	
int main (){
	int n;
	set<int> b;
	cin >>n;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<n;i++){
		int tol = 1;
		int j = i+1;
		while(j<n){
			if(a[j]>a[i]) {
				tol++;
				j++;
				i++;
			}
			else{
				b.insert(tol);
				break;
			}
		}
	}
	 set<int>::reverse_iterator r;
	for(r = b.rbegin(); r != b.rend();){
		cout << *r << endl;
		r =  b.rend();
	}
	return 0;
}
