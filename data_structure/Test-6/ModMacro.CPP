#include <stdio.h>
#define P(a, b) a % b
int main() {
  int i, m, n;
  freopen("ModMacro.in", "r", stdin);
  freopen("ModMacro.out", "w", stdout);
  scanf("%d%d", &m, &n);
  //**************************************
  for (int i = m; i <= n; i++) {
    if (!(P(i, 21))) {
      printf("%d ", i);
    }
  }
  //======================================
  return 0;
}