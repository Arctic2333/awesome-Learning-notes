#include "stdio.h"
#include "string.h"
const int N0 = 1000;

char *index(char *s,char *sub)  //��s�в���sub���ҵ��������ַ���ַ���Ҳ������ؿ�
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
    while (*p++ = *q++);                //��s��p��λ��ɾ��t
    insStr(s, r, p1);  //��s��p1��λ�ò���r
  }
  puts(s);
  return 0;
}