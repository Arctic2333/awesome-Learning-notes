#include "conio.h"
#include "stdio.h"
int BinarySearch(int a[], int n,
                 int key)  // n表示整数的个数，key表示待查找的整数
{
  //************************************************
  int mid, hig, low;        //定义指向中间高位和low的元素
  hig = n - 1;              //为高位指针赋初值
  low = 0;                  //地位赋初值
  while (low <= hig) {      //到low大于hig时代表未找到退出循环
    mid = (hig + low) / 2;  //为mid赋值
    if (a[mid] == key) {
      return mid + 1;           //当找到到的时候返回该数的下标
    } else if (a[mid] > key) {  //如果当前的数的值大于k
      hig = mid - 1;            //当前的mid-1赋值给hig
    } else if (a[mid] < key) {  //如果当前的数的值小于k
      low = mid + 1;            //当前的mid+1赋值给low
    }
  }
  return 0;  //失败返回0
  //================================================
}
int main() {
  int *g, n, K;
  freopen("BiSearch.in", "r", stdin);
  freopen("BiSearch.out", "w", stdout);
  scanf("%d", &n);
  g = new int[n];
  scanf("%d", &K);
  for (int i = 0; i < n; i++) scanf("%d", &g[i]);
  printf("%d\n", BinarySearch(g, n, K));
  delete[] g;
  return 0;
}
