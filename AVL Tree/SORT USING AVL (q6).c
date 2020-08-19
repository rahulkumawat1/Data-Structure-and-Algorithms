#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mem (Node*)malloc(sizeof(Node))

typedef struct node
{
	int data,counter;
	struct node *left,*right;
	int height;
}Node;

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int height(Node *head)
{
	if(!head)
		return 0;
	return head->height;

}
 
Node *rightRotate(Node *head)
{
	Node *x = head->left;
	Node *y = x->right;
	x->right = head;
	head->left = y;
	head->height = max(height(head->left),height(head->right)) + 1;
	x->height =  max(height(x->left),height(x->right)) + 1;
	return x;
}

Node *leftRotate(Node *head)
{
	Node *x = head->right;
	Node *y = x->left;
	x->left = head;
	head->right = y;
	head->height = 1 + max(height(head->left),height(head->right));
	x->height = 1 + max(height(x->left),height(x->right));
	return x;
}

Node *insert(Node *head,int i)
{
	if(!head)
	{
		head = mem;
		head->data = i;
		head->height = 1;
		head->counter = 1;
		head->left = head->right = NULL;
		return head;
	}
	else if(head->data>i)
		head->left = insert(head->left,i);
	else if(head->data<=i)
		head->right = insert(head->right,i);

	head->height = 1 + max(height(head->left),height(head->right));
	int b = height(head->left)-height(head->right);
	if(b>1)
	{
		if(i >= head->left->data)
		{
			head->left = leftRotate(head->left);
			head =  rightRotate(head);
		}
		else
			head =  rightRotate(head);
	}
	if(b<-1)
	{
		if(i >= head->right->data)
		{
			head =  leftRotate(head);
			
		}
		else
		{
			head->right = rightRotate(head->right);
			head =  leftRotate(head);
		}
	}
	return head;

}

int getbalance(Node *n)
{
	if(!n)
		return 0;
	return height(n->left)-height(n->right);
}

Node *search(Node *head,int i)
{
	if(!head)
		return NULL;
	if(i==head->data)
		return head;
	if(i<head->data)
		return search(head->left,i);
	else
		return search(head->right,i);
}

Node *MIN(Node *head)
{
	if(!head->left)
		return head;
	MIN(head->left);
}

Node *deleteNode(Node *head,int i)
{
	if(!head)
		return NULL;
	if(i<head->data)
		head->left = deleteNode(head->left,i);
	else if(i>head->data)
		head->right = deleteNode(head->right,i);
	else
	{
		if(!head->left)
			return head->right;
		else if(!head->right)
			return head->left;
		Node *x = MIN(head->right);
		head->data = x->data;
		head->right = deleteNode(head->right,x->data);
	}
	
	head->height = 1 + max(height(head->left),height(head->right));
	int b = height(head->left)-height(head->right);
	if(b>1)
	{
		if(getbalance(head->left)<0)
		{
			head->left = leftRotate(head->left);
			return rightRotate(head);
		}
		else
			return rightRotate(head);
	}
	if(b<-1)
	{
		if(getbalance(head->right)<=0)
		{
			return leftRotate(head);
			//head = rightRotate(head);
		}
		else
		{
			head->right = rightRotate(head->right);
			return leftRotate(head);
		}
	}
	return head;

}

int getBalance(Node *head,int i)
{
	Node *x = search(head,i);
	if(!x)
		return -1;
	return height(x->left)-height(x->right);
}

void sort(Node *head,int A[],int *i)
{
	if(head)
	{
		sort(head->left,A,i);
		while(head->counter--)
		{
			A[*i] = head->data;
			*i = *i + 1;
		}
		sort(head->right,A,i);
	}
}

int isAVL(Node *head)
{
	if(!head)
		return 1;
	int b = height(head->left)-height(head->right);
	if(b<-1 || b>1)
		return 0;
	if(isAVL(head->left) && isAVL(head->right))
		return 1;
	else
		return 0;
	
}

int main()
{
	Node *head = NULL,*srch = NULL;
	int i;
	int n;
	scanf("%d",&n);
	int A[n];
	for(i = 0;i<n;i++)
	{
		scanf("%d",&A[i]);
		srch = search(head,A[i]);
		if(srch)
			srch->counter += 1;
		else
			head = insert(head,A[i]);
	}
	i=0;
	sort(head,A,&i);
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");

}
