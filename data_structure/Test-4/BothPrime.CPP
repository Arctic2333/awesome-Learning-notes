#include <stdio.h>
#include <math.h>

int IsPrime(int x) {
  int i, k;
  if (x == 2)
    return 1;
  else if (x % 2 == 0)
    return 0;
  k = int(sqrt(x));
  for (i = 3; i <= k; i = i + 2)
    if (x % i == 0) return 0;
  return 1;
}
int Reverse(int x) {
  //************************************
  int i = 0;
  while (x) {
    i = i * 10 + x % 10;
    x /= 10;
  }
  return i;
  //====================================
}
int main() {
  int m, n, i;
  freopen("BothPrime.in", "r", stdin);
  freopen("BothPrime.out", "w", stdout);
  scanf("%d%d", &m, &n);
  //**************************************
  int flag = 0;
  for (i = m; i <= n; i++) {
    if (IsPrime(i) && IsPrime(Reverse(i))) {
      if (flag) {
        printf(" %d", i);
      } else {
        printf("%d", i);
        flag = 1;
      } 
    }
  }
  //======================================
  return 0;
}
