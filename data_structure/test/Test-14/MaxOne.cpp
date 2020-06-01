#include <iostream>

#include "conio.h"
#include "stdio.h"
using namespace std;
int maxone(int a[], int low, int up)  // low表示一组数的下标下界，up表示上界
{
  //************************************************
  if (low + 1 == up || low == up) {
    return max(a[low], a[up]);
  }
  int mid = (low + up) / 2;
  return max(maxone(a, low, mid), maxone(a, mid + 1, up));

  //================================================
}
int main() {
  int *g, n;
  freopen("MaxOne.in", "r", stdin);
  freopen("MaxOne.out", "w", stdout);
  scanf("%d", &n);
  g = new int[n];
  for (int i = 0; i < n; i++) scanf("%d", &g[i]);
  printf("%d\n", maxone(g, 0, n - 1));
  delete[] g;
  return 0;
}
