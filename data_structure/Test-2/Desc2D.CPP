#include <stdio.h>
int main() {
  int b[20][20];
  int n, m, i, j, k, temp;
  freopen("Desc2D.in", "r", stdin);
  freopen("Desc2D.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &b[i][j]);
  //**************************************
  // 列排序
  for (j = 0; j < m; j++) {
    for (i = 0; i < n; i++)
      for (k = i; k < n; k++) {
        if (b[k][j] > b[i][j]) {
          temp = b[k][j];
          b[k][j] = b[i][j];
          b[i][j] = temp;
        }
      }
  }
  // 行排序
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      for (k = j; k < m; k++) {
        if (b[i][k] > b[i][j]) {
          temp = b[i][k];
          b[i][k] = b[i][j];
          b[i][j] = temp;
        }
      }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) printf("%d ", b[i][j]);
    printf("\n");
  }

  //=======================================
  return 0;
}
