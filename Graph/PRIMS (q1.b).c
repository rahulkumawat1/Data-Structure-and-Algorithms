#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define mem (Vertex*)malloc(sizeof(Vertex))
#define M 1001

typedef struct vertex
{
	int data;
	int weight;
	struct vertex *next;
}Vertex;

void Weight_dist(int N,Vertex *V[N])
{
	int i=0,j=0,w;
	Vertex *temp;
	for(i=0;i<N;i++)
	{
		temp = V[i];
		while(temp)
		{
			scanf("%d",&w);
			temp->weight = w;
			temp = temp->next;
		}
	}
}

void Graph_by_list(int N,Vertex *V[N])
{
	Vertex *temp;
	int i=0,k=0,d;
	char c;
	while(i<N)
	{
		scanf("%d",&d);
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
	Weight_dist(N,V);
}

int min_key(int N,Vertex *V[N],int key[],int inMst[])
{
	int min_ind,Min = INT_MAX;
	for(int i=0;i<N;i++)
	{
		if(!inMst[i] && key[i]<Min)
		{	
			Min = key[i];
			min_ind = i;	
		}
	}
	return min_ind;
}

int prims(int N,Vertex *V[N])
{
	int key[N],inMst[N];
	for(int i=0;i<N;i++)
	{
		key[i] = INT_MAX;
		inMst[i] = 0;
	}
	key[0] = 0;
	int v;
	Vertex *temp;
	for(int i=0;i<N-1;i++)
	{
		v = min_key(N,V,key,inMst);
		inMst[v] = 1;
		temp = V[v];
		while(temp)
		{
			if(!inMst[temp->data] && temp->weight<key[temp->data])
				key[temp->data] = temp->weight;
			temp = temp->next;
		}	
	}
	int total_wei = 0;
	for(int i=0;i<N;i++)
		  total_wei += key[i];
	return total_wei;
}

int main()
{
	int N;
	scanf("%d",&N);
	Vertex *V[N],*temp;
       	Graph_by_list(N,V);
	printf("%d",prims(N,V));
	
}
