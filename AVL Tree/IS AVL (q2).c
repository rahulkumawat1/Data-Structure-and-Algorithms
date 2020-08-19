#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define mem (Node*)malloc(sizeof(Node))

typedef struct node
{
	int data;
	struct node *left,*right;
}Node;

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

void insert(Node **head)
{
	int d;
	char c;
	scanf("%c",&c);
	while(c==' '||c==')')
		scanf("%c",&c);
	if(c=='(')
	{
		if(scanf("%d",&d))
		{
			(*head) = mem;
			(*head)->data = d;
			(*head)->left = (*head)->right = NULL;
			insert(&((*head)->left));
			insert(&((*head)->right));
		}
	}
}

int isAVL(Node *head,int *height,int *isBST,int *min,int *max1)
{
	if(!head)
	{
		*isBST = 1;
		*height = 0;
		return 1;
	}
	int lh = 0;
	int rh = 0;
	int lisBST = 0;
	int risBST = 0;
	int lmin = INT_MAX;
        int rmin = INT_MAX;
	int rmax = INT_MIN;
        int lmax = INT_MIN;
	int l = isAVL(head->left,&lh,&lisBST,&lmin,&lmax);
	int r = isAVL(head->right,&rh,&risBST,&rmin,&rmax);
	*height = 1 + max(lh,rh);
	if(!head->left)
		*min = head->data;
	if(!head->right)
		*max1 = head->data;
	if(lisBST && risBST && head->data > lmax && head->data < rmin)
	{
		*isBST = 1;
	}
	else
		return 0;

	if(lh-rh<=1 || lh-rh>=-1)
		return l&&r;
	else
		return 0;
}

int main()
{
	Node *head = NULL;
	insert(&head);
	int height = 0;
        int isBST = 0;
	int min = 0;
	int max = 0;
	printf("%d",isAVL(head,&height,&isBST,&min,&max));
}
