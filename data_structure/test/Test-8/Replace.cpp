#include "stdio.h"
#include "string.h"
const int N0 = 1000;

char *index(char *s,char *sub)  //在s中查找sub，找到返回首字符地址，找不到返回空
{
  int i = 0, j = 0;
  char *p = sub;
  if (*sub == '\0') return NULL;
  //******************************************
  return strstr(s, sub);
  //==========================================
}
void insStr(char *s, char *r, char *p) {
  char *pi, *pj;
  //******************************************
	int rlen = strlen(r);
	strcat(r,p);
	*p='\0';
	strcat(s,r);
	*(r+rlen) = '\0';
  //==========================================
}
int main() {
  char s[N0 + 1], t[N0 + 1], r[N0 + 1], *p, *p1, *q;
  int tlen;
  freopen("Replace.in", "r", stdin);
  freopen("Replace.out", "w", stdout);
  gets(s);
  gets(t);
  gets(r);
  tlen = strlen(t);
  while (p = p1 = index(s, t)) {
    q = p + tlen;
    while (*p++ = *q++);                //在s中p的位置删除t
    insStr(s, r, p1);  //在s中p1的位置插入r
  }
  puts(s);
  return 0;
}