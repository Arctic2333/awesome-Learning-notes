#include <stdio.h>

#include <iostream>
using namespace std;
int main() {
  int sc[6] = {500, 100, 50, 10, 5, 1};  // 6种零钞的面值
  int num[6] = {0};  // 存储找零最优方案，即6种零钞的数目
  float m;
  int mint;  // 存放当前零钱面值总额
  int i;

  freopen("ChangeNote.in", "r", stdin);
  freopen("ChangeNote.out", "w", stdout);

  cin >> m;  // 输入零钱金额
  //************************************************
  i = 0;
  m *= 100;
  mint = m;
  while (mint) {
    while (sc[i] <= mint) {
      num[i] = mint/sc[i];
      mint %= sc[i];
    }
    i++;
  }
  //=================================================
  for (i = 0; i < 6; i++)
    if (num[i] != 0) switch (i) {
        case 0:
          cout << "  伍圆: " << num[0] << endl;
          break;
        case 1:
          cout << "  壹圆: " << num[1] << endl;
          break;
        case 2:
          cout << "  伍角: " << num[2] << endl;
          break;
        case 3:
          cout << "  壹角: " << num[3] << endl;
          break;
        case 4:
          cout << "  伍分: " << num[4] << endl;
          break;
        default:
          cout << "  壹分: " << num[5] << endl;
      }

  return 0;
}
