#include "stdio.h"
#include "string.h"
const int N0 = 1000;

char *index(char *s,
            char *sub)  //��s�в���sub���ҵ��������ַ���ַ���Ҳ������ؿ�
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
      ;  // ��s��p��λ��ɾ��sub
  }
  puts(s);
  return 0;
}