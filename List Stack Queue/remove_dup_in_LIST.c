#include<stdio.h>
#include<stdlib.h>
void main();
void create();
void print();
void remove_duplicate();
typedef struct LIST
{
	int data;
	struct LIST *prev;
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
			case 'r': remove_duplicate(&head);break;
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
		(*head)->prev = NULL;
		(*head)->next = NULL;
		old = *head;
		while(fscanf(fp,"%d",&num)==1)
		{
			newnode = (list*)malloc(sizeof(list));
			newnode->data = num;
			newnode->prev = old;
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
void remove_duplicate(list **head)
{
	list *temp,*m,*n,*p,*rem;
	temp = *head;
	while(temp!=NULL)
	{
		p = temp->next;
		while(p!=NULL)
		{
			if((temp->data) == (p->data))
			{
				m = p->prev;
				n = p->next;
				m->next = n;
				n->prev = m;
				rem = p;
				free(rem);
			}
			p = p->next;
		}
		temp = temp->next;
	}
}
