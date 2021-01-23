#include "stdio.h"
#define MaxSize 100

typedef
	struct
	{	int list[MaxSize];
  		int num;	// 块中元素个数 
  	}block_type;	// 二级检索块数据类型

typedef
	struct
	{	int key;	// 最大键值
		block_type *ptr;	// 指向检索块的指针
	}node;	// 一级索引表的结点类型

node *index;	// 指向一级索引表的指针
int n;	// 二级检索块的个数

void init_table()	// 建立分块检索表
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
