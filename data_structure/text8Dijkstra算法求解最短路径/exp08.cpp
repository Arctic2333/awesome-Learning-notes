#include <iostream>
#include <stdio.h>
using namespace std;

int vex_num;		// ��ʾվ�����

int start_point;	// ��ʾ����վ������

char *station;		// ָ��վ��������д��ĸ���ַ������ָ��

int **adjmat;		// ָ���ʾ�ڽӾ���Ķ�ά�����ָ��

int *prev;			// ָ���ʾ���·����ǰ��վ��λ�������ָ��

int *dist;			// ָ����̾��������ָ��

void path_Dijkstra(int u)   // ������·����Dijkstra�㷨
{//************************************************
	int min,v;
	int *S = new int[vex_num];
	for(int i=0;i<vex_num;i++){
		dist[i]=adjmat[u][i];
		prev[i]=u;
		S[i]=0;
	} 
	S[u]=1;
	prev[u]=-1;
	for(int i=1;i<vex_num;i++){
		min=9999;
		for(int j=0;j<vex_num;j++){
			if(!S[j] && dist[j]<min){
				v=j;
				min=dist[j];
			}
		}
		if(min==9999)
			break;
		S[v]=1;
		for(int j=0;j<vex_num;j++){
			if(!S[j] && dist[v]+adjmat[v][j]<dist[j]){
				dist[j]=dist[v]+adjmat[v][j];
				prev[j]=v;
			}
		}
	}
 //================================================
}

void output_path(int v)   // ����prev[]��dist[]���ĳһ�յ�����·������̾���
{//************************************************
	int u=v;
	int top=-1;
	int stack[vex_num];
	while(u!=-1){
		stack[++top]=u;
		u=prev[u];
	}
	cout<<station[stack[top--]]<<" ";
	while(top!=-1){
		cout<<"--> "<<station[stack[top--]]<<" ";
	}
	cout<<": "<<dist[v]<<endl;
 //================================================
}

int main()
{ int i, j;
  freopen("exp08.in", "r", stdin);
  freopen("exp08.out", "w", stdout);
  cin>>vex_num;
  cin>>start_point;
  // �����ͳ�ʼ��վ������ //
  station=new char[vex_num];
  for(i=0; i<vex_num; i++) station[i]='A'+i;
  // ������ʾ�ڽӾ���Ķ�ά���� //
  adjmat=new int* [vex_num];
  for(i=0; i<vex_num; i++) adjmat[i]=new int[vex_num];
  // ��ʼ���ڽӾ��� //
  for(i=0; i<vex_num; i++)
    for(j=0; j<vex_num; j++) cin>>adjmat[i][j];
  // ������ʾ���·����ǰ��վ��λ�õ����� //
  prev=new int[vex_num];
  // ������ʾ��̾�������� //
  dist=new int[vex_num];
  // ������·���յ��ǰ���;��� //
  path_Dijkstra(start_point-1);
  // ������·���;��� //
  for(i=0; i<vex_num; i++)
    if(i!=start_point-1) output_path(i);
  return 0;
}

