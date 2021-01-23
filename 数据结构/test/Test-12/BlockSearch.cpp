#include "stdio.h"
#define MaxSize 100

typedef
	struct
	{	int list[MaxSize];
  		int num;	// ����Ԫ�ظ��� 
  	}block_type;	// ������������������

typedef
	struct
	{	int key;	// ����ֵ
		block_type *ptr;	// ָ��������ָ��
	}node;	// һ��������Ľ������

node *index;	// ָ��һ���������ָ��
int n;	// ����������ĸ���

void init_table()	// �����ֿ������
{	int i, j, m, k, data;
	scanf("%d", &n);
	index=new node[n];
	for(i=0; i<n; i++)
	{	scanf("%d%d", &k, &m);
		index[i].key=k;
		index[i].ptr=new block_type;
		index[i].ptr->num=m;
		for(j=0; j<m; j++)
		{	scanf("%d", &data);
			index[i].ptr->list[j]=data;
		}
	}
}

void search(int k)
{//************************************************
	int in=-1,jn=-1;
	
	for(int i=0;i<n;i++)
		if(k<=index[i].key)
		{
			in=i;
			for(int j=0;j<index[i].ptr->num;j++)
				if(k==index[i].ptr->list[j])
					jn=j;
			break;
		}
	
	if(in!=-1)
		printf("%d,%d",in,jn);
	else
		printf("-1");
 //================================================
}

int main()
{	int K;	
	freopen("BlockSearch.in", "r", stdin);
//	freopen("BlockSearch.out", "w", stdout);
	scanf("%d", &K);
	init_table();
	search(K);
	return 0;
}
