#include "stdio.h"
#include "conio.h"
int Item(int d, int n)
{
//************************************************
	if(n==1)
		return d;
	return Item(d,n-1)*10+d;

//================================================
}

int main()
{	int d, n, sum=0, i;
//	freopen("SumofND_.in", "r", stdin);
//	freopen("SumofND_.out", "w", stdout);
	scanf("%d%d", &d, &n);
	for(i=1; i<=n; i++)
	  sum = sum + Item(d, i);
	printf("%d", sum);
	return 0;
}
