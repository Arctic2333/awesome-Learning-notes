#include <stdio.h>
int main() {
  int b[5][5];
  int i, j;
  freopen("DeltaM.in", "r", stdin);
  freopen("DeltaM.out", "w", stdout);
  //**********************************
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++) {
      scanf("%d", &b[i][j]);
    }
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++) {
      if (i < j) {
        b[i][j] -= 10;
      }
      if (i >= j) {
        b[i][j] += 10;
      }
    }
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  //==================================
  return 0;
}
