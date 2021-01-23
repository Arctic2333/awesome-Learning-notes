#include "stdio.h"
#define Size 300
#include<iostream>
using namespace std;

typedef
	struct node
	{	int data;
  		struct node *lp, *rp;
  	}btnode;	// 二叉链表结点类型

btnode *search(btnode *bp, int key)	// 在bp所指根结点的二叉检索树中检索key
					// 若key不存在, 插入该键值
					// 函数返回key所在结点的地址
{//************************************************
		
	if(!bp)
	{
		bp=new btnode;
		bp->data=key;
		bp->lp=NULL;
		bp->rp=NULL;
		return bp;
	}
	
	btnode *p=bp;
	while(1)
	{		
		if(key<p->data)
		{
			if(!(p->lp))
			{
				btnode *node=new btnode;
				node->data=key;
				node->lp=NULL;
				node->rp=NULL;
				p->lp=node;
				return p;				
			}
			p=p->lp;
		}
		
		if(key>p->data)
		{						
			if(!(p->rp))
			{
				btnode *node=new btnode;
				node->data=key;
				node->lp=NULL;
				node->rp=NULL;
				p->rp=node;
				return p;				
			}
			p=p->rp;
		}
		
		if(key==p->data)
			return p;
	}
	return p;

 //================================================
}

void travel_mid(btnode *bp)	// 中序遍历二叉树
{	btnode *stack[Size];
	int top=-1;	
	while (bp!=NULL || top!=-1)
	{	while(bp!=NULL)
		{	stack[++top]=bp;
			bp=bp->lp;
		}
		if(top!=-1)
		{	bp=stack[top--];
			printf("%d  ", bp->data);
			bp=bp->rp;
		}
	}
}

void free_tree(btnode *bp)
{	btnode *queue[Size];
	int front=0, rear=0;
	queue[++rear]=bp;
	while (front!=rear)
	{	bp=queue[++front];
		if (bp->lp!=NULL) queue[++rear]=bp->lp;
		if (bp->rp!=NULL) queue[++rear]=bp->rp;
		delete bp;
	}
}

int main()
{	btnode *root=NULL;
	int n, i, k;	

	freopen("BTSearch.in", "r", stdin);
//	freopen("BTSearch.out", "w", stdout);
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{	scanf("%d", &k);
	 	if (root==NULL) root=search(root, k);
	 	else search(root, k);
	}
	travel_mid(root);
	return 0;
}
