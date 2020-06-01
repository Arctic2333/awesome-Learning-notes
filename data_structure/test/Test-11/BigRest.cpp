#include "stdio.h"
#include "string.h"

int main()
{	char data[256];	// 存放原整数串
 	int n;	// 指示原整数的位数
 	int digit;	// 指示剩余整数位数 
	int m;	// 存放待删除的位数 
	char stack[256], top = -1;	// 寄存保留的高位到低位中的最大整数每位数字的栈，及栈顶指针 
	char stack2[256], top2 = -1;	// 用于实现逆序输出的栈及栈顶指针 
	int i = 0;	// 指示当前扫描的整数位置 
//	freopen("BigRest.in", "r", stdin);
//	freopen("BigRest.out", "w", stdout);
	scanf("%s", data);
	n = strlen(data);
	scanf("%d", &m);
	digit = n-m; 
	//************************************************
	if(!m)
	{
		printf("%s",data);
		return 0;
	}
	int last_pick=-1,max,maxi; 
	while(digit--)
	{
		max=-1;
		maxi=-1;
		for(int i=n-(digit+1);i>=last_pick+1;i--)
		{
			if(data[i]>=max)
			{
				maxi=i;
				max=data[i];
			}
		}
		
		if(n-(digit+1)==maxi)
		{
			
			while(data[maxi]!='\0')
				stack[++top]=data[maxi++];
			break;
		}
		
		stack[++top]=data[maxi];
		last_pick=maxi;
	}
	
	stack[++top]='\0';
	printf("%s",stack);
		
	//=================================================
	return 0;
}

 
