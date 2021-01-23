#include "conio.h"
#include "stdio.h"

int partition(
    int a[], int low,
    int up)  // 函数实现将数组分为前小、后大的2组
             // low表示分割前下标的下界，up表示上界，函数返回分割点下标
{
  //************************************************
  int x = a[up];
  int i = low - 1;
  int temp;
  for (int j = low; j < up; j++) {
    if (a[j] <= x) {
      i = i + 1;
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  temp = a[i + 1];
  a[i + 1] = a[up];
  a[up] = temp;
  return i + 1;

  //================================================
}

void quick_sort(int a[], int s, int t)  // 快速排序的递归算法
{
  int m;
  if (s < t) {
    m = partition(a, s, t);
    quick_sort(a, s, m - 1);
    quick_sort(a, m + 1, t);
  }
}

int main() {
  int *g, n;
  freopen("QuickSort.in", "r", stdin);
  freopen("QuickSort.out", "w", stdout);
  scanf("%d", &n);
  g = new int[n];
  for (int i = 0; i < n; i++) scanf("%d", &g[i]);
  quick_sort(g, 0, n - 1);
  for (int i = 0; i < n; i++) printf("%5d", g[i]);
  delete[] g;
  return 0;
}
