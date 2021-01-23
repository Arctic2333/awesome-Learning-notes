#include "stdio.h"
#include "string.h"
#include "math.h"
#define N0 100
struct node
{	int rank, ac;
	char name[10], account[30];
	double score;
}stu[N0];

struct node1
{	char name[10], account[30];
	bool atend;
}acc[N0];

int n, num;

void readData()
{	char s[150];
	n=0;
	while( gets(s)!=NULL )
	{	if( strstr( strupr(s), "ÐÕÃû")!=NULL )break;
		if( strstr( strupr(s), "FJAU")==NULL ) continue;  // n??????????FJAU ???
		n++;
		sscanf(s, "%*d%s%d", stu[n].account, &stu[n].ac); 
	}
	num=0;
	while( gets(s)!=NULL )
	{	if( strstr( strupr(s), "FJAU")==NULL ) continue; // num ????????
		num++;
		sscanf(s, "%s%s", acc[num].name, acc[num].account); 		
	}
}

void cal()
{//************************************************
	int rank=1;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=num;j++){
			if(!acc[j].atend && !strcmp(stu[i].account,acc[j].account))
			{
				stu[i].rank=rank++;
				acc[j].atend=true;
				strcpy(stu[i].name,acc[j].name);
				if(stu[i].ac>=1)
					stu[i].score=101-(stu[i].rank*sqrt(stu[i].rank));
				else
					stu[i].score=10;
				break;
			}
		}
	}
	for(int i=1;i<=num;i++)
		if(!acc[i].atend)
		{
			strcpy(stu[++n].name,acc[i].name);
			stu[n].score=0;
		}
//=================================================
}

void printData()
{	int i;
	for( i=1; i<=n; i++)
		if( stu[i].name[0]!=0 )
		printf("%s %.3f\n", stu[i].name, stu[i].score);
}

int main()
{	
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	readData();
	cal();
	printData();
	return 0;
}