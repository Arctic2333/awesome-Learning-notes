#include <stdio.h>
#include <string.h>
int main() {
  char s[100];
  int i, key;
  freopen("Cesar.in", "r", stdin);
  freopen("Cesar.out", "w", stdout);
  scanf("%d", &key);
  getchar();
  gets(s);
  //**********************************
  for (i = 0; i < strlen(s); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') s[i] = (s[i] - 'a' + key) % 26 + 'a';
    printf("%c", s[i]);
  }
  //==================================
  return 0;
}