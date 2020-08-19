#include<stdio.h>
#include<stdlib.h>
void main();
void enqueue();
void print();
int dequeue();
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
	int element,d,n;
	list *head;
	head = NULL;
	while(1)
	{
		fscanf(fp,"%c",&c);
		switch(c)
		{
			case 'e': fscanf(fp,"%d",&element); enqueue(&head,element);break;
			case 'd': d = dequeue(&head);fprintf(fp1,"%d\n",d);break;
			case 'p': fscanf(fp,"%d",&n);print(&head,n,fp1);break;
			case 's': fclose(fp);fclose(fp1);return;
		}
	}

}
void enqueue(list **head,int element)
{
	if(*head==NULL)
	{
		*head = (list*)malloc(sizeof(list));
		(*head)->data = element;
		(*head)->next = NULL;
	}	
	else
	{
		list *temp = *head;
		while((temp->next)!=NULL)
			temp = temp->next;
		list *newnode;
		newnode = (list*)malloc(sizeof(list));
		newnode->data = element;
		newnode->next = NULL;
		temp->next = newnode;
	}
}
int dequeue(list **head)
{
	int d;
	if((*head)==NULL)
		d = -1;
	else
	{
		d = (*head)->data;
		list *temp = *head;
		*head = (*head)->next;
		free(temp);
	}	
	return d;
}
void print(list **head,int n,FILE *fp1)
{
	list *temp = *head;
	if(temp==NULL)
		fprintf(fp1,"-1\n");
	else if(n==0)
	{
		while(temp!=NULL)
		{	fprintf(fp1,"%d ",temp->data);
			temp = temp->next;
		}
		fprintf(fp1,"\n");
	}
	else if(n>0)
	{
		int i,num=0;
		while(temp!=NULL)
			{num++;
			temp = temp->next;
			}
		temp = *head;
		if(n<=num)
		{	for(i=1;i<=n;i++)
				{fprintf(fp1,"%d ",temp->data);
					temp = temp->next;
				}
				fprintf(fp1,"\n");
		}
		else
		{
			for(i=1;i<=num;i++)
			{
				fprintf(fp1,"%d ",temp->data);
				temp = temp->next;
			}
			fprintf(fp1,"END\n");
		}
		
	}
}

