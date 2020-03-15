#include <stdio.h>
#include <math.h>
int IsPrime(int x) {
  //************************************
  int i, k;
  if (x == 2)
    return 1;
  else if (x % 2 == 0)
    return 0;
  k = int(sqrt(x));
  for (i = 3; i <= k; i = i + 2)
    if (x % i == 0) return 0;
  return 1;
  //====================================
}
int main() {
  int m, n, i;
  freopen("Primes.in", "r", stdin);
  freopen("Primes.out", "w", stdout);
  scanf("%d%d", &m, &n);
  //**************************************
  for (i = m; i <= n; i++) {
    if (IsPrime(i)) {
      printf("%d ", i);
    }
  }
  //======================================
  return 0;
}