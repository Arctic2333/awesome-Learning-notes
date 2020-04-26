#include "stdio.h"
#include "string.h"
const int N0 = 500;
int longIntegerSum(char a[], char b[], int c[]) {
  char *pa, *pb;
  int *pc, len = 0;
  pa = a + strlen(a) - 1;  // pa指向第一个正整数的最低位
  pb = b + strlen(b) - 1;  // pb指向第二个正整数的最低位
                           //******************************************
  pc = c;
  int loop = strlen(a) >= strlen(b) ? strlen(b) : strlen(a);  // 循环的次数
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
  char a[N0 + 1], b[N0 + 1];      // 用两个字符数组存放两个加数
  int c[N0 + 5] = {0}, *pc, len;  // 变量len表示相加结果的位数
  // 用一个整型数组存放两数相加的和，c[0]存放最低位，c[len-1]存放最高位
  freopen("BigInt.in", "r", stdin);
  freopen("BigInt.out", "w", stdout);
  gets(a);
  gets(b);
  len = longIntegerSum(a, b, c);
  for (pc = c + len - 1; pc >= c; pc--)  // 输出结果倒序输出
    printf("%d", *pc);
  printf("\n");
  return 0;
}
