#include "stdio.h"
const int N0 = 100;
int *maxInt(int a[], int n) {
  int *p, *pm;
  //******************************************
  pm = a;
  for (p = a + 1; p < a + n; p++) {
    if (*p > *pm) {
      pm = p;
    }
  }
  return pm;
  //==========================================
}
int main() {
  int a[N0], n, *p;
  freopen("MaxAddr.in", "r", stdin);
  freopen("MaxAddr.out", "w", stdout);
  scanf("%d", &n);
  for (p = a; p < a + n; p++) scanf("%d", p);
  p = maxInt(a, n);
  printf("%d\n", *p);
  return 0;
}