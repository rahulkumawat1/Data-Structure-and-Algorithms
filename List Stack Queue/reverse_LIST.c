#include<stdio.h>
#include<stdlib.h>
void main();
void create();
void print();
void reverse();
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
	list *head;
	head = (list*)malloc(sizeof(list));
	while(1)
	{
		fscanf(fp,"%c",&c);
		switch(c)
		{
			case 'c': create(&head,fp);break;
			case 'p': print(head,fp1);break;
			case 'r': reverse(&head);break;
			case 's': fclose(fp);fclose(fp1);return;
		}
	}

}
void create(list **head,FILE *fp)
{
	list *old,*newnode;
	int num;
	if(fscanf(fp,"%d",&num)==0)
	{
		free(*head);
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
void reverse(list **head)
{
	list *m = *head;
	if(m->next != NULL)
	{
		list *k,*n;
		n = m->next;
		m->next = NULL;
		while(n!=NULL)
		{
			k = m;
			m = n;
			n = n->next;
			m->next = k;
		}
		*head = m;
	}
}
