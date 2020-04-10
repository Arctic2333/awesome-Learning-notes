#include "stdio.h"
#include "string.h"
int sumInt(char *s) {
  int sum = 0, t = 0, sign = 1;
  char *p = s;
  bool inNumber = false;  // 用于表示当前*p是否为数字
  //******************************************
  while ((*p) != '\0') {
    if (((*p) >= '0' && (*p) <= '9') || (*p) == '-') {
      t = 0;
      sign = 1;
      if (*p == '-') {
        sign = -1;
        p++;
      } else {
        t = *p - '0';
        p++;
      }
      while (((*p) >= '0' && (*p) <= '9')) {
        t = t * 10 + (*p - '0');
        p++;
      }
      p--;
      sum += t * sign;
    }
    p++;
  }
  //==========================================
  return sum;
}

int main() {
  char s[1000 + 1];
  freopen("Addition.in", "r", stdin);
  freopen("Addition.out", "w", stdout);
  gets(s);
  printf("%d\n", sumInt(s));
  return 0;
}