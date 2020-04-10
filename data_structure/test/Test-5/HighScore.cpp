#include "stdio.h"
const int N0 = 500;
struct node {
  int no;              // 学号
  int c, m, e, total;  // 语数英三科成绩及总分
};

node *maxTotal(node a[], int n) {
  node *pm, *p;
  //******************************************
  pm = a;
  for (p = a + 1; p < a + n; p++) {
    if (p->total > pm->total) {
      pm = p;
    }
    if (p->total == pm->total) {
      if (p->c > pm->c) {
        pm = p;
      }
    }
    if (p->total == pm->total && p->c == pm->c) {
      if (p->no < pm->no) {
        pm = p;
      }
    }
  }
  //==========================================
  return pm;
}

int main() {
  node a[N0], *p;
  int n, i;
  freopen("HighScore.in", "r", stdin);
  freopen("HighScore.out", "w", stdout);
  scanf("%d", &n);
  for (p = a, i = 1; p < a + n; p++, i++) {
    scanf("%d%d%d", &p->c, &p->m, &p->e);
    p->total = p->c + p->m + p->e;
    p->no = i;
  }
  p = maxTotal(a, n);
  printf("%d %d\n", p->no, p->total);
  return 0;
}