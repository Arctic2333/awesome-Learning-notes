#include "conio.h"
#include "stdio.h"
int BinarySearch(int a[], int n,
                 int key)  // n��ʾ�����ĸ�����key��ʾ�����ҵ�����
{
  //************************************************
  int mid, hig, low;        //����ָ���м��λ��low��Ԫ��
  hig = n - 1;              //Ϊ��λָ�븳��ֵ
  low = 0;                  //��λ����ֵ
  while (low <= hig) {      //��low����higʱ����δ�ҵ��˳�ѭ��
    mid = (hig + low) / 2;  //Ϊmid��ֵ
    if (a[mid] == key) {
      return mid + 1;           //���ҵ�����ʱ�򷵻ظ������±�
    } else if (a[mid] > key) {  //�����ǰ������ֵ����k
      hig = mid - 1;            //��ǰ��mid-1��ֵ��hig
    } else if (a[mid] < key) {  //�����ǰ������ֵС��k
      low = mid + 1;            //��ǰ��mid+1��ֵ��low
    }
  }
  return 0;  //ʧ�ܷ���0
  //================================================
}
int main() {
  int *g, n, K;
  freopen("BiSearch.in", "r", stdin);
  freopen("BiSearch.out", "w", stdout);
  scanf("%d", &n);
  g = new int[n];
  scanf("%d", &K);
  for (int i = 0; i < n; i++) scanf("%d", &g[i]);
  printf("%d\n", BinarySearch(g, n, K));
  delete[] g;
  return 0;
}
