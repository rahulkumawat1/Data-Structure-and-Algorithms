#include<stdio.h>
#include<stdlib.h>
void main();
int create();
void print();
void ins_mid();
int mid(int n)
{
	int num;
	if(n%2==0)
		num = n/2;
	else
		num = n/2+1;
	return (num+1);
}
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
	int n;
	list *head;
	head = (list*)malloc(sizeof(list));
	while(1)
	{
		fscanf(fp,"%c",&c);
		switch(c)
		{
			case 'c': n = create(&head,fp);break;
			case 'p': print(head,fp1);break;
			case 'i': ins_mid(&head,n,fp);break;
			case 's': fclose(fp);fclose(fp1);return;
		}
	}

}
int create(list **head,FILE *fp)
{
	list *old,*newnode;
	int num,n=0;
	if(fscanf(fp,"%d",&num)==0)
	{
		free(*head);
		*head=NULL;
	}
	else
	{
		n=1;
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
			n++;
		}
	}
	return n;
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
void ins_mid(list **head,int n,FILE *fp)
{
	list *old = *head;
	int i=1;
	if(old==NULL)
	{
		*head = malloc(sizeof(list));
		int num;
		fscanf(fp,"%d",&num);
		(*head)->data = num;
		(*head)->next = NULL;
	}
	else
	{
	while(i<mid(n)-1)
	{
		old = old->next;
		i++;
	}
	list *newnode;
	newnode = (list*)malloc(sizeof(list));
	fscanf(fp,"%d",&newnode->data);
	newnode->next = old->next;
	old->next=newnode;}
}
