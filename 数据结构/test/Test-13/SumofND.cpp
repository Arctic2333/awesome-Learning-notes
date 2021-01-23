#include "stdio.h"
#include "conio.h"
int Item(int d, int n)
{
//************************************************
	int temp=0;	
	for(int i=0;i<n;i++)
		temp=temp*10+d;
	return temp;
//================================================
}

int main()
{	int d, n, sum=0, i;
//	freopen("SumofND.in", "r", stdin);
//	freopen("SumofND.out", "w", stdout);
	scanf("%d%d", &d, &n);
	for(i=1; i<=n; i++)
	  sum = sum + Item(d, i);
	printf("%d", sum);
	return 0;
}
