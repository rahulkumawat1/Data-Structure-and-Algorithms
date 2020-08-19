#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define scan(a) scanf("%d",&a)
#define forl(i,a,b) for(int i=a;i<b;i++)

typedef struct Edge
{
	int src,dst,weight;
}Edge;

int main()
{
	int v,e;
	scan(v);
	scan(e);
	Edge E[e];
	forl(i,0,e)
	{
		scan(E[i].src);
		scan(E[i].dst);
		scan(E[i].weight);
	}
	int s;
	scan(s);
	int dist[v];
	forl(i,0,v)
	{
		if(s==i)
			dist[i] = 0;
		else
			dist[i] = INT_MAX;
	}
	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			if(dist[E[j].src]!=INT_MAX && dist[E[j].dst]>dist[E[j].src]+E[j].weight)
				dist[E[j].dst] = dist[E[j].src] + E[j].weight;
		}
	}
	for(int i=0;i<v;i++)
		printf("%d %d\n",i,dist[i]);
}
