#include <stdio.h>

#include <iostream>
using namespace std;

int n, C;  // 物品数与背包容量
int *w;    // 存储物品体积的数组首地址
int *v;    // 存储物品价值的数组首地址

int **Value;  // 指向记录前i个物品在背包容量j时可装填的最大价值的备忘录的指针
int *item;    // 指向最优解组合向量的指针

int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int min(int a, int b) {
  if (a > b) return b;
  return a;
}

void computeTable()  // 动态规划计算Value备忘录
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

void findWhatInBag(int i, int j)  // 回溯搜索最优物品装填组合
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

void print()  // 输出结果
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
