#include <stdio.h>
int Gcd(int x, int y) {
  //**************************************
  if (y == 0) return x;
  return Gcd(y, x % y);
  //======================================
}
int main() {
  int a, b;
  freopen("GCD.in", "r", stdin);
  freopen("GCD.out", "w", stdout);
  scanf("%d%d", &a, &b);
  //**************************************
  printf("%d", a * b / Gcd(a, b));
  //======================================
  return 0;
}