#include <stdio.h>

#include <iostream>
using namespace std;
int main() {
  int sc[6] = {500, 100, 50, 10, 5, 1};  // 6���㳮����ֵ
  int num[6] = {0};  // �洢�������ŷ�������6���㳮����Ŀ
  float m;
  int mint;  // ��ŵ�ǰ��Ǯ��ֵ�ܶ�
  int i;

  freopen("ChangeNote.in", "r", stdin);
  freopen("ChangeNote.out", "w", stdout);

  cin >> m;  // ������Ǯ���
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
          cout << "  ��Բ: " << num[0] << endl;
          break;
        case 1:
          cout << "  ҼԲ: " << num[1] << endl;
          break;
        case 2:
          cout << "  ���: " << num[2] << endl;
          break;
        case 3:
          cout << "  Ҽ��: " << num[3] << endl;
          break;
        case 4:
          cout << "  ���: " << num[4] << endl;
          break;
        default:
          cout << "  Ҽ��: " << num[5] << endl;
      }

  return 0;
}
