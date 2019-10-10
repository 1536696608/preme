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
	float mincost[MinLen];//�洢Ȩֵ 
	int minmid,i,j,m;//mindid�洢��СȨֵ��Ӧ�ĵ� 
	float sum = 0;
	int mst[MinLen];//��һ���� 

	mincost[1] = 0.;//ȡ��ʼ��Ϊ1 
	mst[0] =  1;
	for(i = 2;i <= p;i++)
	{
		mst[i] = 1;//���е�Ĭ�����Ϊ1 
		mincost[i] = graph[1][i];
		
	}
	for(i = 2; i <= p;i++)
	{
		 float min = MaxCost;
		 for(j = 2;j <= p;j++)
		 {
		 	if(mincost[j] < min&&mincost[j] != 0.)
		 	{
		 		min = mincost[j]; //�ҳ�������С�ĵ� 
		 		minmid = j;
			 }
		 }
		 sum += min;
		 mincost[minmid] = 0.;
		 printf("%d---->%d\n",mst[minmid],minmid);
		 for(j = 2;j <= p;j++)//���»����� 
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
	printf("�������ĸ�����ߵ�����\n");
	int p,e,i,j;
	float graph[MaxEdge][MaxEdge];//����ͼ���ڽӾ��� 
	int p1,p2;//��ʱ�������Ȩֵ 
	float val,re;
	scanf("%d%d",&p,&e);
	for(i = 0;i < MaxEdge;i++)//��ʼ�� 
	{
		for(j = 0;j < MaxEdge;j++)
		{
			graph[i][j] = MaxCost;
		}
	}
	for(i = 1; i <= e;i++)
	{
		
		printf("��������������Ȩֵ\n");
		scanf("%d%d%f",&p1,&p2,&val);
		graph[p1][p2] = val;
		graph[p2][p1] = val;	
	}
	re = Prime(graph,p);// 
	printf("result = %0.2f",re);
}