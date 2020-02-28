#include <stdio.h>

int main() {
  int b[5][5];
  int i, j;
  long sum;
  freopen("Sum2ndD.in", "r", stdin);
  freopen("Sum2ndD.out", "w", stdout);
  //**********************************
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++) {
      scanf("%d", &b[i][j]);
    }
  int n = 5;
  j = 4, i = 0;
  while (n > 0) {
    sum += b[i][j];
    i++;
    j--;
    n--;
  }
  printf("%d", sum);
  //==================================
  return 0;
}
