/*
	autor:juzongquan
	project:prime
	num:2018217702
*/
#include<stdio.h>
#include<stdlib.h>
#define MaxCost 600.
#define MaxEdge 50
#define MinLen 20
#define Cost 5 
float Prime(float graph[][MaxEdge],int p)
{
	float mincost[MinLen];//存储权值 
	int minmid,i,j,m;//mindid存储最小权值对应的点 
	float sum = 0;
	int mst[MinLen];//上一个点 

	mincost[1] = 0.;//取初始点为1 
	mst[0] =  1;
	for(i = 2;i <= p;i++)
	{
		mst[i] = 1;//所有点默认起点为1 
		mincost[i] = graph[1][i];
		
	}
	for(i = 2; i <= p;i++)
	{
		 float min = MaxCost;
		 for(j = 2;j <= p;j++)
		 {
		 	if(mincost[j] < min&&mincost[j] != 0.)
		 	{
		 		min = mincost[j]; //找出花销最小的点 
		 		minmid = j;
			 }
		 }
		 sum += min;
		 mincost[minmid] = 0.;
		 printf("%d---->%d\n",mst[minmid],minmid);
		 for(j = 2;j <= p;j++)//更新花销点 
		 {
		 	if(graph[minmid][j] < mincost[j])
			 {
			 	mincost[j] = graph[minmid][j];
			 	mst[j] = minmid;
			  } 
		 }
	}
	return sum;
 } 
int main()
{
	printf("请输入点的个数与边的条数\n");
	int p,e,i,j;
	float graph[MaxEdge][MaxEdge];//定义图（邻接矩阵） 
	int p1,p2;//临时输入点与权值 
	float val,re;
	scanf("%d%d",&p,&e);
	for(i = 0;i < MaxEdge;i++)//初始化 
	{
		for(j = 0;j < MaxEdge;j++)
		{
			graph[i][j] = MaxCost;
		}
	}
	for(i = 1; i <= e;i++)
	{
		
		printf("输入两点与其间的权值\n");
		scanf("%d%d%f",&p1,&p2,&val);
		graph[p1][p2] = val;
		graph[p2][p1] = val;	
	}
	re = Prime(graph,p);// 
	printf("result = %0.2f",re);
}
