//实验条件在源码末尾
#include <iostream>
#include <stdio.h>
using namespace std;

const int Size=30;
const double INF=9999;		// infinity (无穷大)
int vexnum;					// total number of vertex (顶点总数) 
int adjmat[Size][Size];		// adjacent matrix (邻接矩阵)
int mark[Size];				// vector of visiting mark of vertex (顶点访问标记向量)
int visitnum;				// number of visited vertex for one search (一次搜索中被访问顶点数)
int adjnum;					// number of connected components (连通分量数) 

void readData()
{	int i,j;
	cin>>vexnum;			// input vexnum 
	for(i=0; i<vexnum; i++)
		for(j=0; j<vexnum; j++)
		{	cin>>adjmat[i][j];
			if(i!=j && adjmat[i][j]==0) adjmat[i][j]=INF;
		}
}

void Search(int v)			// one time search, v represents the starting vertex
{//************************************************
	if(vexnum == visitnum)
		return;
	mark[v]=1;
	visitnum++;
	for(int i =0;i<vexnum;i++){
		if(!mark[i] && adjmat[v][i] != INF && i!=v)
			Search(i);
	}

 //================================================
}

int main()
{	int i;
	freopen("exp07.in", "r", stdin);
	freopen("exp07.out", "w", stdout);
	readData();							// input data 
	for(i=0; i<vexnum; i++) mark[i]=0;	// initialze the visiting mark   初始化访问标记向量
	visitnum=0;
	Search(0);							// one time search from vertex 0 
	if(visitnum==vexnum) cout<<"All vertexs are connected.\n";
	else 
	{	adjnum=1;
		//************************************************
		
		for(int i = 0;i<vexnum;i++){
			if(!mark[i]){
				Search(i);
				adjnum++;
			}
		}

 		//================================================
		cout<<"The number of connected components is "<<adjnum<<".\n";
	}
	return 0;
}
/*实验七  图的连通性判定与连通分量计算
实验目的
1. 熟悉图的存储结构
2. 掌握图的深度优先搜索和广度优先搜索算法
3. 掌握掌握图遍历在图的连通问题中的应用
实验环境
1. 操作系统：Windows XP
2. 编程环境：Turbo C 3.0及以上，或Visual C++ 6.0，或C++ Builder 6.0，或Visual C# 2005，或Dev-C++，任选以上所列之一。
实验内容
已知某地区的公路网以图表示，图中的顶点表示站点，任意两站点间的路段以带权的边构成的邻接矩阵表示，矩阵中非零元表示两个站点间存在直接的路段，否则没有路段。
打开E:\Test文件夹中的exp07.cpp文件，补充编写所需代码。程序首先进行图的连通性判定，若图连通则输出连通信息，否则继续计算和输出图的连通分量数。
输入数据在文件exp07.in中，首行的整数是站点的总数n(1<n<=30)；第2行开始的n行中，每行n个整数，是这n个站点构成的公路网的邻接矩阵。例如，
6
0 1 3 4 9 0
1 0 9 9 0 0
3 9 0 0 6 8
4 9 0 0 5 7
9 0 6 5 0 4
0 0 8 7 4 0
主函数中，在调用读入数据函数readData()时，会自动将矩阵中的零元（除对角线保持0以外）替换成无穷大（9999）。
Search(int v)函数实现从顶点v出发的一次搜索过程，并累计访问顶点数。
若图是连通的，则输出文件exp07.out中包含如下文字：
All vertexs are connected.
否则，计算和输出连通分量数，输出文件的内容则如下例：
	The number of connected components is 2.
解题思路
利用一次深度优先或者广度优先搜索过程中对访问顶点数的计数，并判断其与图的顶点总数是否相等来判定图的连通性。
如果图不连通，则继续从下一个未被访问的顶点出发再进行一次搜索，如此反复，直到已遍历图的所有顶点，累计的搜索次数即是图的连通分量数。*/