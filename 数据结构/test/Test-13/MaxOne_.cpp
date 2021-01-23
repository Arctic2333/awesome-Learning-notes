#include "stdio.h"
#include "conio.h"
int maxone(int a[],int n)
{	int temp;
//************************************************
	if(n==1)
		return *a;
	if(a[n-1]>a[n-2])
		a[n-2]=a[n-1];
	maxone(a,n-1);
	


//=================================================
}
int main()
{	int g[100],n;
//	freopen("MaxOne_.in", "r", stdin);
//	freopen("MaxOne_.out", "w", stdout);
	scanf("%d", &n);
	for(int i=0; i<n; i++)	scanf("%d",&g[i]);
	printf("%d", maxone(g,n));
	return 0;
}

