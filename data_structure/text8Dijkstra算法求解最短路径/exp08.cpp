#include <iostream>
#include <stdio.h>
using namespace std;

int vex_num;		// 表示站点个数

int start_point;	// 表示出发站点的序号

char *station;		// 指向站点名（大写字母）字符数组的指针

int **adjmat;		// 指向表示邻接矩阵的二维数组的指针

int *prev;			// 指向表示最短路径上前驱站点位置数组的指针

int *dist;			// 指向最短距离数组的指针

void path_Dijkstra(int u)   // 求解最短路径的Dijkstra算法
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

void output_path(int v)   // 依据prev[]和dist[]输出某一终点的最短路径和最短距离
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
  // 建立和初始化站名数组 //
  station=new char[vex_num];
  for(i=0; i<vex_num; i++) station[i]='A'+i;
  // 建立表示邻接矩阵的二维数组 //
  adjmat=new int* [vex_num];
  for(i=0; i<vex_num; i++) adjmat[i]=new int[vex_num];
  // 初始化邻接矩阵 //
  for(i=0; i<vex_num; i++)
    for(j=0; j<vex_num; j++) cin>>adjmat[i][j];
  // 建立表示最短路径上前驱站点位置的数组 //
  prev=new int[vex_num];
  // 建立表示最短距离的数组 //
  dist=new int[vex_num];
  // 求解最短路径终点的前趋和距离 //
  path_Dijkstra(start_point-1);
  // 输出最短路径和距离 //
  for(i=0; i<vex_num; i++)
    if(i!=start_point-1) output_path(i);
  return 0;
}

