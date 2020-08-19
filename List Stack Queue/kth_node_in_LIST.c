#include<stdio.h>
#include<stdlib.h>
void main();
int create();
void print();
int find_knode();
typedef struct LIST
{
	int data;
	struct LIST *next;
}list;
void main()
{
	FILE *fp,*fp1;
	fp = fopen("input.txt","r");
	fp1 = fopen("output.txt","w");
	char c;
	int k,kth_node;
	list *head;
	head = (list*)malloc(sizeof(list));
	while(1)
	{
		fscanf(fp,"%c",&c);
		switch(c)
		{
			case 'c': create(&head,fp);break;
			case 'p': print(head,fp1);break;
			case 'f': fscanf(fp,"%d",&k);kth_node=find_knode(&head,k);fprintf(fp1,"%d\n",kth_node);break;
			case 's': fclose(fp);fclose(fp1);return;
		}
	}

}
int create(list **head,FILE *fp)
{
	list *old,*newnode;
	int num;
	if(fscanf(fp,"%d",&num)==0)
	{
		*head=NULL;
	}	
	else
	{
		(*head)->data = num;
		(*head)->next = NULL;
		old = *head;
		while(fscanf(fp,"%d",&num)==1)
		{
			newnode = (list*)malloc(sizeof(list));
			newnode->data = num;
			newnode->next = NULL;
			old->next = newnode;
			old = newnode;
		}
	}
}
void print(list *head,FILE *fp1)
{
	list *old = head;
	if(head==NULL)
		fprintf(fp1,"-1");
	else{
	while(old!=NULL)
	{
		fprintf(fp1,"%d ",old->data);
		old = old->next;
	}}
	fprintf(fp1,"\n");
}
int find_knode(list **head,int k)
{
	int n=0,kth_node;
	list *old = *head;
	while(old!=NULL)
	{
		n++;
		old = old->next;
	}
	if(n==0 || k>n)
		kth_node = -1;
	else
	{
		int i=1;
		old = *head;
		while(i<n-k+1)
		{old = old->next;
		i++;}
		kth_node = old->data;
	}
	return kth_node;
}
