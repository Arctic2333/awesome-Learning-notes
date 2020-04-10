#include <stdio.h>
#include <string.h>
int main() {
  char c[20][20], temp[20];
  int n, i, j;
  freopen("StrSort.in", "r", stdin);
  freopen("StrSort.out", "w", stdout);
  scanf("%d", &n);
  getchar();
  for (i = 0; i < n; i++) gets(c[i]);
  //**************************************
  for (i = 0; i < n; i++) {
    int t = i;
    for (j = i + 1; j < n; j++)
      if (strcmp(c[t], c[j]) > 0) t = j;

    strcpy(temp, c[i]);
    strcpy(c[i], c[t]);
    strcpy(c[t], temp);
  }
  for (i = 0; i < n; i++) printf("%s\n", c[i]);
  //=======================================
  return 0;
}