#include "stdio.h"
#include "string.h"

int main()
{	char data[256];	// ���ԭ������
 	int n;	// ָʾԭ������λ��
 	int digit;	// ָʾʣ������λ�� 
	int m;	// ��Ŵ�ɾ����λ�� 
	char stack[256], top = -1;	// �Ĵ汣���ĸ�λ����λ�е��������ÿλ���ֵ�ջ����ջ��ָ�� 
	char stack2[256], top2 = -1;	// ����ʵ�����������ջ��ջ��ָ�� 
	int i = 0;	// ָʾ��ǰɨ�������λ�� 
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

 
