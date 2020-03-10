#include <stdio.h>
int main() {
  struct student {
    int num;
    char name[10];
    int score;
  };
  struct student stu[20];
  int n, i, flag = 0;
  freopen("ExceList.in", "r", stdin);
  freopen("ExceList.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%s", &stu[i].num, stu[i].name);
    scanf("%d", &stu[i].score);
  }
  //********************************************************
  for (i = 0; i < n; i++)
    if (stu[i].score >= 90) {
      printf("%d %s %d\n", stu[i].num, stu[i].name, stu[i].score);
      flag = 1;
    }
  if (!flag) printf("No\n");

  //========================================================
  return 0;
}
