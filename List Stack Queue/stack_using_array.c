#include<stdio.h>
void main();
void push();
int pop();
void print();
void main()
{
	FILE *fp = fopen("input.txt","r");
	FILE *fp1 = fopen("output.txt","w");
	int element,n;
	int max;
	fscanf(fp,"%d",&max);
	int top = max,pop_v;
	int stk[max];
	char c;
	while(1)
	{
		fscanf(fp,"%c",&c);
		switch(c)
		{
			case 'p':fscanf(fp,"%d",&element);push(stk,element,max,&top,fp1);break;
			case 't':pop_v = pop(stk,&top,max);fprintf(fp1,"%d\n",pop_v);break;
			case 'd':fscanf(fp,"%d",&n);print(stk,n,fp1,top,max);break;
			case 's':fclose(fp);fclose(fp1);return;
		}
	}
}
void push(int stk[],int element,int max,int *t,FILE *fp1)
{
	if((*t)==0)
	{
		fprintf(fp1,"999\n");
	}
	else
	{(*t)--;
	 int i = *t;
	 stk[i] = element;
	}
}
int pop(int stk[],int *t,int max)
{
	int pop_v;
	if((*t)==max)
		pop_v = -1;
	else
	{
		pop_v = stk[*t];
		(*t)++;
	}
	return pop_v;
}
void print(int stk[],int n,FILE *fp1,int top,int max)
{
	int i;
	if(top==max)
		fprintf(fp1,"-1\n");
	else if(n==0)
	{
		for(i=top;i<max;i++)
			fprintf(fp1,"%d ",stk[i]);
		fprintf(fp1,"\n");
	}
	else if(n>0)
	{
		if(n<=max-top)
		{
			for(i=top;i<top+n;i++)
				fprintf(fp1,"%d ",stk[i]);
			fprintf(fp1,"\n");
		}
		else
		{
			for(i=top;i<max;i++)
				fprintf(fp1,"%d ",stk[i]);
			fprintf(fp1,"END\n");
		}
	}
}
