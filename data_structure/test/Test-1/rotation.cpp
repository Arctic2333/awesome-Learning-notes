#include "stdio.h"
const int N=101;
int a[2*N][2*N]={ 0 };
struct node
{	int row, col;
}dir[4]={ {1, 1}, {-1, 1},{-1, -1},{1, -1}};  // 逆时针走法从第 n 行 第一列开始走

int main()
{	int x, y, x1, y1, k;
	int n, d=0;
	freopen("rotation.in", "r", stdin);
	freopen("rotation.out", "w", stdout);
	scanf("%d", &n);
	//*********************************
	int n1 = n * n,m=0,ch = n * n;
	while (n1)
	{
		n1/=10;
		m++;
	}  // 求出固定宽度
	x = n;
	y = 1;
	a[x][y] = ch;
	k = 0;
	while (ch > 0)
	{
		x1 = x + dir[d].row;
		y1 = y + dir[d].col;
		if(x1 < 1 || y1 < 1 || x1 > 2*n-1 || y1 > 2*n-1 || a[x1][y1]!=0){  // 试探
			d = (d+1)%4;
			x1 = x + dir[d].row;
			y1 = y + dir[d].col;
		}
		x= x1;
		y = y1;
		a[x][y]=ch--;
	}
	for(register int  i=1; i<=2*n-1; i++ ){
		for(register int  j=1; j<=2*n-1; j++)
			if( a[i][j]!=0 ) printf("%0*d", m, a[i][j]);			
			else if( i<=n && j<n+i || i>n && j<3*n-i)
				printf("%*c", m, ' ');
		printf("\n");
	}
	//=================================
	return 0;
}