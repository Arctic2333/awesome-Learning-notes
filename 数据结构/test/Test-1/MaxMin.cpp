#include <stdio.h>
int main()
{
	int a[20]={0};
	int i,Max,Min;
	FILE *fp;
	if ((fp=fopen("MaxMin.in","r"))!=NULL){
		freopen("MaxMin.in", "r", stdin);
		freopen("MaxMin.out", "w", stdout);
	}
	//*********************************
	for ( i = 0; i < 20; i++)
	{
		scanf("%d",&a[i]);
	}
	Max = -999;
	Min = 999;
	for (i = 0; i < 20; i++){
		if(a[i] >= Max)
			Max = a[i];
		if(a[i] <= Min)
			Min = a[i];
	}
	printf("%d %d",Max,Min);
	//=================================
	return 0;
}