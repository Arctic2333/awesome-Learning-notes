#include "stdio.h"
#include "string.h"
const int N0 = 500;
int longIntegerSum(char a[], char b[], int c[]) {
  char *pa, *pb;
  int *pc, len = 0;
  pa = a + strlen(a) - 1;  // paָ���һ�������������λ
  pb = b + strlen(b) - 1;  // pbָ��ڶ��������������λ
                           //******************************************
  pc = c;
  int loop = strlen(a) >= strlen(b) ? strlen(b) : strlen(a);  // ѭ���Ĵ���
  int temp = loop;
  char *dig = strlen(a) >= strlen(b) ? a : b;
  for (; loop > 0; loop--) {
    *pc = (*pa - '0') + (*pb - '0') + (*pc);
    if (*pc >= 10) {
      *pc -= 10;
      pc++;
      pa--;
      pb--;
      *pc += 1;
    } else {
      pc++;
      pa--;
      pb--;
    }
  }
  loop = strlen(dig) - temp;
  dig = dig + loop - 1;
  for (; loop > 0; loop--) {
    *pc = (*dig - '0') + (*pc);
    if (*pc >= 10) {
      *pc -= 10;
      pc++;
      dig--;
      *pc += 1;
    } else {
      dig--;
      pc++;
    }
  }
  if (*pc)
    len = pc - c + 1;
  else
    len = pc - c;
  //==========================================
  return len;
}
int main() {
  char a[N0 + 1], b[N0 + 1];      // �������ַ���������������
  int c[N0 + 5] = {0}, *pc, len;  // ����len��ʾ��ӽ����λ��
  // ��һ������������������ӵĺͣ�c[0]������λ��c[len-1]������λ
  freopen("BigInt.in", "r", stdin);
  freopen("BigInt.out", "w", stdout);
  gets(a);
  gets(b);
  len = longIntegerSum(a, b, c);
  for (pc = c + len - 1; pc >= c; pc--)  // �������������
    printf("%d", *pc);
  printf("\n");
  return 0;
}
