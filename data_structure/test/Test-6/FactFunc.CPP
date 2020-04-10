#include <stdio.h>
long factSum(int n) {
  //**************************************
  long sum = 0, temp = 1;
  for (int i = 1; i <= n; i++) {
    temp *= i;
    sum += temp;
  }
  return sum;
  //======================================
}
int main() {
  int i, n;
  long s = 0;
  freopen("FactFunc.in", "r", stdin);
  freopen("FactFunc.out", "w", stdout);
  scanf("%d", &n);
  //**************************************
  printf("%ld", factSum(n));
  //======================================
  return 0;
}
