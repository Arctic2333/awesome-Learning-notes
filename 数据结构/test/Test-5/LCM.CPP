#include <stdio.h>
int Gcd(int x, int y) {
  //**************************************
  if (y == 0) return x;
  return Gcd(y, x % y);
  //======================================
}
int main() {
  int a, b, c, t1, t2;
  freopen("LCM.in", "r", stdin);
  freopen("LCM.out", "w", stdout);
  scanf("%d%d%d", &a, &b, &c);
  //**************************************
  printf("%d %d", Gcd(Gcd(a, b), c),
         (a * b / Gcd(a, b)) * c / Gcd((a * b / Gcd(a, b)), c));
  //======================================
  return 0;
}