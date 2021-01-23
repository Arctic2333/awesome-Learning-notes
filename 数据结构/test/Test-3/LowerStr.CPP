#include <stdio.h>
#include <string.h>
int main() {
  char s[30];
  int i, j;
  freopen("LowerStr.in", "r", stdin);
  freopen("LowerStr.out", "w", stdout);
  gets(s);
  //**********************************
  for (i = 0; i < strlen(s); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      for (j = i; j < strlen(s)-1; j++) {
        s[j] = s[j + 1];
      }
      i--;
    }
  }
  printf("%s", s);
  //==================================
  return 0;
}