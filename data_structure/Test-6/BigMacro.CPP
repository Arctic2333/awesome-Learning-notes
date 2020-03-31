#include <stdio.h>
#define MAX(a, b) (a > b) ? a : b
int main() {
  int x, y, z, m;
  freopen("BigMacro.in", "r", stdin);
  freopen("BigMacro.out", "w", stdout);
  scanf("%d%d%d", &x, &y, &z);
  //**************************************
  printf("%d", MAX((MAX(x, y)), z));
  //======================================
  return 0;
}