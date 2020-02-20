#include "stdio.h"
#include "string.h"
const int N=100;
int a[N+1][N+1];
int n;
bool isMaster(int i, int j)   // 判定a[i][j]是否为主斜线上的最大元素
{	//*********************************
	int x = i-1,y = j-1;
	while (x>=1 && y >= 1 )
	{
		if(a[x][y] > a[i][j])
			return false;
		x--;
		y--;
	}
	x = i+1;
	y = j+1;
	while (x <= n && y <= n)
	{
		if(a[x][y] > a[i][j])
			return false;
		x++;
		y++;
	}
	return true;
	//=================================
}

bool isSlaver( int i, int j )   // 判定a[i][j]是否为次斜线上的最小元素
{	//*********************************
	int x = i+1,y = j-1;
	while (x <=n  && y >= 1 )
	{
		if(a[x][y] < a[i][j])
			return false;
		x++;
		y--;
	}
	x = i-1;
	y = j+1;
	while (x >= 1 && y <= n)
	{
		if(a[x][y] < a[i][j])
			return false;
		x--;
		y++;
	}
	return true;
	//=================================
}


int main()
{	int i, j, total=0;
	freopen( "total.in", "r", stdin );
	freopen( "total.out", "w", stdout);
	scanf("%d", &n);
	for( i=1; i<=n; i++)
		for( j=1; j<=n; j++) scanf("%d", &a[i][j]);
	for( i=1; i<=n; i++)
		for( j=1; j<=n; j++)
			if( isMaster(i,j) && isSlaver(i,j) ) total+=a[i][j];
	printf("%d\n", total);
	return 0;
}
