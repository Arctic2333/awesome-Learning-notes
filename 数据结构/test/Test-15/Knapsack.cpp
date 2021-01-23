#include <stdio.h>

#include <algorithm>
#include <iostream>
using namespace std;
typedef struct {
  char name[16];  // ����
  double p;       // ��ֵ
  double w;       // ����
  double r;       // ����
} good;
bool comp(good a, good b) { return a.r > b.r; }
int main() {
  int n, i, j, k;
  good *G, temp;
  double C;      // �洢��ǰ��������
  double value;  // ������ǰ��װ��Ʒ�ܼ�

  freopen("Knapsack.in", "r", stdin);
  freopen("Knapsack.out", "w", stdout);

  cin >> n;
  cin >> C;
  G = new good[n];
  for (i = 0; i < n; i++) {
    cin >> G[i].name;
    cin >> G[i].p;
    cin >> G[i].w;
    G[i].r = G[i].p / G[i].w;
  }
  //************************************************
  sort(G, G + n, comp);
  i = 0;
  double z;
  while (C > 0 + 1e-8 && i < n) {
    z = 0;
    while (C > 0 + 1e-8 && z < G[i].w - 1e-8) {
      C -= 0.1;
      z += 0.1;
    }
    value += G[i].r * z;
    if (z) cout << G[i].name << ": " << z << "Kg" << endl;
    i++;
  }

  //=================================================
  cout << "Total price: " << ((int)(100 * value + 0.5)) * 0.01 << endl;
  return 0;
}
