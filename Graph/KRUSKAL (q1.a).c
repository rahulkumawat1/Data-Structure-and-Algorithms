#include<stdio.h>
#include<stdlib.h>
#define mem (Vertex*)malloc(sizeof(Vertex))
#define M 1001

int parent[M];
int rank[M];

typedef struct vertex
{
	int data;
	struct vertex *next;
}Vertex;

typedef struct edge
{
	int src,dst,weight;
}Edge;

int Graph_by_list(int N,Vertex *V[N])
{
	Vertex *temp;
	int i=0,k=0,d,noe=0;
	char c;
	while(i<N)
	{
		scanf("%d",&d);
		noe++;
		if(k==0)
		{
			V[i] = mem;
			temp = V[i];
			k = 1;
		}
		else
		{
			temp->next = mem;
			temp = temp->next;
		}
		temp->data = d;
		temp->next = NULL;
		scanf("%c",&c);
		if(c=='\n')
		{
			k=0;
			i++;
		}	
	}
	return noe/2;

}

int Edge_dist(Edge E[],int N,Vertex *V[N])
{
	int i=0,j=0,w;
	Vertex *temp;
	for(i=0;i<N;i++)
	{
		temp = V[i];
		while(temp)
		{
			scanf("%d",&w);
			if(i<temp->data)
			{
				E[j].src = i;
				E[j].dst = temp->data;
				E[j++].weight = w;
			}
			temp = temp->next;
		}
	}
}

int Edge_sort(Edge E[],int n)
{
	int j;
	Edge key;
	for(int i=1;i<n;i++)
	{
		key = E[i];
		j = i-1;
		while(j>=0 && E[j].weight > key.weight)
		{
			E[j+1] = E[j];
			j--;
		}	
		E[j+1] = key;
	}
}

void Union(int x,int y)
{
	if(rank[x]<rank[y])
		parent[x] = y;
	else if(rank[x]>rank[y])
		parent[y] = x;
	else
	{
		parent[y] = x;
		rank[x]++;
	}
}

int find(int x)
{
	if(x==parent[x])
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

int checkCycle(Edge E)
{
	int x = find(E.src);
	int y = find(E.dst);
	if(x==y)
		return 1;
	Union(x,y);
	return 0;
}

int kruskal(int N,Vertex *V[N],Edge E[],int noe)
{
	int min = 0;
	Edge_sort(E,noe);
	for(int i=0;i<noe;i++)
	{
		if(!checkCycle(E[i]))
			min += E[i].weight;
	}
	return min;
}

int main()
{
	for(int i=0;i<M;i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
	int N;
	scanf("%d",&N);
	Vertex *V[N],*temp;
       	int noe = Graph_by_list(N,V);
	Edge E[noe];
	Edge_dist(E,N,V);
	printf("%d",kruskal(N,V,E,noe));
	
}
