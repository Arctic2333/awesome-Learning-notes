#include "stdio.h"
#include "conio.h"
int maxone(int a[],int n)
{
//************************************************
	int maxOfA=*a;
	for(int i=1;i<n;i++)
		if(a[i]>maxOfA)
			maxOfA=a[i];
	return maxOfA;


//=================================================
}
int main()
{	int g[100],n;
//	freopen("MaxOne.in", "r", stdin);
//	freopen("MaxOne.out", "w", stdout);
	scanf("%d", &n);
	for(int i=0; i<n; i++)	scanf("%d",&g[i]);
	printf("%d", maxone(g,n));
	return 0;
}

