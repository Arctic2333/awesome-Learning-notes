#include <math.h>
#include <stdio.h>
long fan(int a, int n) {
  //**************************************
  long temp = a, sum;
  for (int i = 0; i < n; i++) {
    sum += temp;
    temp = temp * 10 + a;
  }
  return sum;
  //======================================
}
int main() {
  int i, a, n;
  long s = 0;
  freopen("RepDigit.in", "r", stdin);
  freopen("RepDigit.out", "w", stdout);
  scanf("%d%d", &a, &n);
  //**************************************
  printf("%d", fan(a, n));
  //======================================
  return 0;
}
