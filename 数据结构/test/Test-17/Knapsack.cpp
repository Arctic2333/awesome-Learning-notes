#include <stdio.h>

#include <iostream>
using namespace std;

int n, C;  // ��Ʒ���뱳������
int *w;    // �洢��Ʒ����������׵�ַ
int *v;    // �洢��Ʒ��ֵ�������׵�ַ

int **Value;  // ָ���¼ǰi����Ʒ�ڱ�������jʱ��װ�������ֵ�ı���¼��ָ��
int *item;    // ָ�����Ž����������ָ��

int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int min(int a, int b) {
  if (a > b) return b;
  return a;
}

void computeTable()  // ��̬�滮����Value����¼
{
  int i, j;
  // *********************************************
  i = j = 0;
	int mW = w[1];
  for (i = 0; i <= n; i++) {  // init
		if(i > 1){
			mW = min(mW,w[i]);
		}
    for (j = 0; j <= C; j++) {
      Value[i][j] = 0;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = mW; j <= C; j++) {
      if (j - w[i] >= 0) {
        Value[i][j] = max(Value[i - 1][j], Value[i - 1][j - w[i]] + v[i]);
      }else{
				Value[i][j] = Value[i-1][j];
			}
    }
  }

  // =============================================
}

void findWhatInBag(int i, int j)  // ��������������Ʒװ�����
{
  if (i > 0)
    if (Value[i][j] == Value[i - 1][j]) {
      item[i] = 0;
      findWhatInBag(i - 1, j);
    } else if (j - w[i] >= 0 && Value[i][j] == Value[i - 1][j - w[i]] + v[i]) {
      item[i] = 1;
      findWhatInBag(i - 1, j - w[i]);
    }
}

void print()  // ������
{
  int i, j;
  /*
  for (i=0; i<=n; i++)
  {	for (j=0; j<=C; j++)
                  cout<<Value[i][j]<<' ';
          cout<<endl;
  }
*/
  cout << "Options: ";
  for (i = 1; i <= n; i++) cout << item[i] << ' ';
  cout << endl;
  cout << "Max Value: " << Value[n][C] << endl;
}

int main() {
  int i, j;
  freopen("Knapsack.in", "r", stdin);
  freopen("Knapsack.out", "w", stdout);
  cin >> n;
  cin >> C;
  w = new int[n + 1];
  w[0] = 0;
  for (i = 1; i <= n; i++) cin >> w[i];
  v = new int[n + 1];
  v[0] = 0;
  for (i = 1; i <= n; i++) cin >> v[i];
  Value = new int *[n + 1];
  for (i = 0; i <= n; i++) Value[i] = new int[C + 1];
  computeTable();
  item = new int[n + 1];
  for (i = 0; i <= n; i++) item[i] = 0;
  findWhatInBag(n, C);
  print();
  return 1;
}
