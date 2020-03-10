#include <stdio.h>
int main() {
  struct student  // 声明一个结构体类型struct student
  {
    int num;
    char name[10];
    int score[3];  // 3门课程成绩
    double avg;    //总分
  };
  struct student stu[20];  //定义含20个元素结构体数组
  int i, j, n, flag = 0;
  freopen("HighList.in", "r", stdin);
  freopen("HighList.out", "w", stdout);
  scanf("%d", &n);
  for (j = 0; j < n; j++) {
    scanf("%d%s", &stu[j].num, stu[j].name);
    for (i = 0; i < 3; i++) scanf("%d", &stu[j].score[i]);
  }
  //********************************************************
  for (i = 0; i < n; i++)
    if ((stu[i].score[0] >= 85 && stu[i].score[1] >= 85 &&
         stu[i].score[2] >= 85) ||
        (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3 >= 90) {
      printf("%d %s\n", stu[i].num, stu[i].name);
      flag = 1;
    }
  if (!flag) printf("No\n");
  //========================================================
  return 0;
}
