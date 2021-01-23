#include "stdio.h"
#include "string.h"
const int N0 = 1000;

char *index(char *s,
            char *sub)  //在s中查找sub，找到返回首字符地址，找不到返回空
{
  int i = 0, j = 0;
  char *p = sub;
  if (*sub == '\0') return NULL;
  //******************************************
  return strstr(s, sub);

  //==========================================
}

int main() {
  char s[N0 + 1], sub[N0 + 1], *p, *q;
  int sublen;
  freopen("DelSubstr.in", "r", stdin);
  freopen("DelSubstr.out", "w", stdout);
  gets(s);
  gets(sub);
  sublen = strlen(sub);
  while (p = index(s, sub)) {
    q = p + sublen;
    while (*p++ = *q++)
      ;  // 在s中p的位置删除sub
  }
  puts(s);
  return 0;
}