#include <stdio.h>
#include <math.h>
struct eType {
  int x;
  int index;
};
eType find(int a[], int n) {
  //**************************************
  int average = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  average = sum / n;
  eType min;
  min.x = a[0];
  min.index = 0;
  int aMin = abs(a[0] - average);
  for (int i = 1; i < n; i++) {
    if (abs(a[i] - average) < aMin) {
      aMin = abs(a[i] - average);
      min.x = a[i];
      min.index = i;
    }
  }
  return min;
  //======================================
}
int main() {
  int a[100];
  int i, n;
  eType f;
  freopen("LDeviation.in", "r", stdin);
  freopen("LDeviation.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  //**************************************
  f = find(a, n);
  printf("%d %d", f.x, f.index);
  //======================================
  return 0;
}