#include "stdio.h"
const int INF=0x7fffffff; //���������
struct ND
{	int data; 
	struct ND *next; 
};

ND *createLink( ) 
{	ND *head, *p;
	int n; 
    head = p = new ND; 
	scanf("%d", &n);
	while( n-- )
	{	p->next = new ND; 
		p = p->next;  
		scanf("%d", &p->data); 
	}
	p->next = NULL; 
	return head;    
}
void printLink( ND *head ) 
{	ND *p=head->next;  
	if( p==NULL )return ;
	while( p )
	{	printf( "%d ",p->data );
		p=p->next;
	}
	printf("\n");
}

void deleteLink( ND *head) 
{	ND *p=head;
	while( p )
	{	head = p->next;
		delete p;
		p = head;
	}
}

ND * megerLink( ND *ha, ND *hb ) //�ϲ�2�����,���غϲ�������ͷ���ĵ�ַ
{	ND *pa=ha->next, *pb=hb->next, *hc, *pc;
	int data, lastData=INF; //lastDataΪ��һ����������������ж��Ƿ�����ͬ����
	hc=pc=new ND;
//************************************************
	while(pa && pb )
	{
		if(pa->data<pb->data)
		{
			pa=pa->next;
			continue;
		}
		else
			if(pa->data>pb->data)
			{
				pb=pb->next;
				continue;
			}
			else
			{
				data=pa->data;
				pa=pa->next;
				pb=pb->next;
			}
			
		if(data==lastData)
			continue;
		ND *next=new ND;
		lastData=next->data=data;
		pc->next=next;
		pc=pc->next;
	}
	pc->next=NULL;

//=================================================
	return hc;
}
int main()
{	ND *ha, *hb, *hc;
	freopen( "Intersect.in", "r", stdin);
	freopen( "Intersect.out", "w", stdout);
	ha = createLink();
	hb = createLink();
	hc = megerLink( ha, hb );
	printLink( hc );
	deleteLink( ha );
	deleteLink( hb );
	deleteLink( hc );
	return 0;
}
