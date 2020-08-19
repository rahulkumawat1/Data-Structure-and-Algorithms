#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mem (Node*)malloc(sizeof(Node))
typedef struct node
{
        int data;
        struct node *left;
        struct node *right;
}Node;

Node *insert(Node **head)
{
	char c;
	int d;
 	scanf("%c",&c);
	while( c==' ' || c==')')
	 scanf("%c",&c);
	if(c=='(')
	{
		if(scanf("%d",&d))
		{
			Node *temp;
			temp = mem;
			temp->data = d;
			temp->left = NULL;
			temp->right = NULL;
			*head = temp;
			insert(&(temp->left));
			insert(&(temp->right));
		}
		else *head = NULL;
	}	
}

Node *search(Node *temp,int k)
{
	if(!temp)
	{	
		//printf("NOT FOUND\n");
		return NULL;
	}
	if(temp->data == k)
	{
		//printf("FOUND\n");
		return temp;
	}
	if(temp->data>k)
		search(temp->left,k);
	else
		search(temp->right,k);
}

Node *findMin(Node *head)
{
	if(head==NULL)
	{	//printf("NIL\n");
		return NULL;}
	else if(!head->left)
	{//printf("%d\n",head->data);
		return head;}
	findMin(head->left);	
}

Node *findMax(Node *head)
{
	if(head==NULL)
	{
		//printf("NIL\n");
		return NULL;
	}
	else if(!head->right)
	{
		//printf("%d\n",head->data);
		return head;
	}
	findMax(head->right);
}

Node *predecessor(Node *head,int i)
{
	Node *temp;
	temp = search(head,i);
	if(temp)
	{
		if(temp->left)
		{
			return findMax(temp->left);
		}
		else
		{
			Node *y = NULL;
			while(head)
			{
				if(head->data > i)
					head = head->left;
				else if(head->data < i)
				{
					y = head;
					head = head->right;
				}
				else
					break;
			}
			if(y==NULL)
			{
				printf("-1\n");
				return NULL;
			}
			else
			{
				return y;
			}
		}
		
	}
	else
	{
		printf("NULL\n");
		return NULL;
	}
}

Node *successor(Node *head,int i)
{
	Node *temp;
	temp = search(head,i);
	if(temp)
	{
		if(temp->right)
		{
			return findMin(temp->right);
		}
		else
		{
			Node *y = NULL;
			while(head)
			{
				if(head->data > i)
				{	y = head;
					head = head->left;}
				else if(head->data < i)
					head = head->right;
				else
					break;
			}
			if(y==NULL)
			{
				printf("-1\n");
				return NULL;
			}
			else
			{
				return y;
			}
		}
		
	}
	else
	{
		printf("NULL\n");
		return NULL;
	}
}

Node *delete(Node *head,int i)
{
	if(!head)
		return head;
	if(i < head->data)
		head->left = delete(head->left,i);
	else if(i > head->data)
		head->right = delete(head->right,i);
	else
	{
		if(!head->left)
		{
			Node *temp = head->right;
			free(head);
			return temp;
		}
		else if(!head->right)
		{
			Node *temp = head->left;
			free(head);
			return temp;
		}
		else
		{
			Node *temp = findMin(head->right);
			head->data = temp->data;
			head->right = delete(head->right,temp->data);
		}
	}
	return head;
}

void inorder(Node *head)
{
	if(head)
	{
		inorder(head->left);
		printf("%d ",head->data);
		inorder(head->right);
	}
}

void preorder(Node *head)
{
	if(head)
	{
		printf("%d ",head->data);
		preorder(head->left);
		preorder(head->right);
	}
}

void postorder(Node *head)
{
	if(head)
	{
		postorder(head->left);
		postorder(head->right);
		printf("%d ",head->data);
		
	}
}

void mirror(Node *head)
{
	printf("( ");
	if(head)
	{
		printf("%d ",head->data);
		mirror(head->right);
		mirror(head->left);
	}
	printf(") ");
}

void paren(Node *head)
{
	printf("( ");
	if(head)
	{ printf("%d ",head->data);
	paren(head->left);
	paren(head->right);}
	printf(") ");
}

int main()
{
        
        Node *head = NULL;
	insert(&head);
	mirror(head);
	printf("\n");
	
}
