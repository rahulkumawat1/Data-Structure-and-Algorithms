#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct node
{
	int key;
	int degree;
	struct node *sibling;
	struct node *child;
	struct node *parent;
}node;

node *getNode(int key);
node *MAKE_HEAP();
node *INSERT(node *H,node *x);
node* BINOMIAL_LINK(node* x,node* y);
node* UNION(node *H1,node *H2);
node* MERGE(node *p,node *q);
node *CONSOLIDATE(node *p);
node *MINIMUM(node *H);
node *EXTRACT_MIN(node **H,int n,node *A[]);
node *DECREASE_KEY(node *H,node *x,int key,int n,node* A[]);
node *DELETE(node *H,node *x,int n,node* A[]);
node *delete_node(node **H,node *m);
node *reverse(node *head);
void print(node *H);
int num_trees(node *H);

int main()
{
	char ch[6],temp;
	int f=1,i,j,k,key,n,count=0;
	node *H=NULL;
	node *x=NULL;
	node *min_ptr=NULL;
	node *t=NULL;
	scanf("%d",&n);
	node *A[n];
	for(int i=0;i<n;i++)
		A[i]=NULL;
	while(f==1)
	{

		scanf("%s",ch);

		if(!(strcmp(ch,"insr")))
		{
			scanf("%d %d",&j,&k);
			x=getNode(k);
			if(A[j]==NULL)
			{

				A[j]=x;
			}
			H=INSERT(H,x);
		}
		else if(!(strcmp(ch,"min")))
		{
			x=MINIMUM(H);
			if(x==NULL)
				printf("-1\n");
			else
				printf("%d\n",x->key);
		}
		else if(!(strcmp(ch,"extr")))
		{
			x=EXTRACT_MIN(&H,n,A);
			if(x==NULL)
				printf("-1\n");
			else
				printf("%d\n",x->key);
			for(int i=0;i<n;i++)
			{
				if(A[i]!=NULL && (A[i]->key==x->key))
					A[i]=NULL;
			}
			free(x);
		}
		else if(!(strcmp(ch,"decr")))
		{
			scanf("%d %d",&j,&k);
			if(A[j]!=NULL)
			{
				x=A[j];
				k=x->key-k;
				H=DECREASE_KEY(H,x,k,n,A);

			}
			else
			{
				printf("-1\n");
			}

		}
		else if(!(strcmp(ch,"del")))
		{
			scanf("%d",&j);
			if(A[j]!=NULL)
			{
				x=A[j];
				H=DELETE(H,x,n,A);
				A[j]=NULL;
			}
			else
			{
				printf("-1\n");
			}

		}
		else if(!(strcmp(ch,"tc")))
		{
			count=num_trees(H);
			printf("%d\n",count);
		}
		else if(!(strcmp(ch,"stop")))
			f=0;
		else
			printf("Wrong input...enter the right input\n");
	}
	scanf("%c",&temp);
}

node *getNode(int key)
{
	node *newNode=(node*)malloc(sizeof(node));
	newNode->parent=NULL;
	newNode->child=NULL;
	newNode->sibling=NULL;
	newNode->degree=0;
	newNode->key=key;
	return newNode;
}

node *MAKE_HEAP()
{
	node *H=NULL;
	return H;
}

node *INSERT(node *H,node *x)
{
	node* H2=MAKE_HEAP();
	H2=x;
	H=UNION(H,H2);
	node* temp=H;
	while(temp!=NULL)
	{
		temp->parent=NULL;
		temp=temp->sibling;
	}
	return H;
}

node* BINOMIAL_LINK(node* x,node* y)
{
	x->parent=y;
	x->sibling=y->child;
	y->child=x;
	y->degree+=1;
	return y;
}

node* UNION(node *H1,node *H2)
{
	if(H1==NULL)
	{
		return H2;
	}
	else if(H2==NULL)
	{
		return H1;
	}
	else
	{
		node *H=MAKE_HEAP();
		node *p=H1;
		node *q=H2;
		H=MERGE(p,q);
		H=CONSOLIDATE(H);
		return H;
	}
}

node* MERGE(node *p,node *q)
{
	if(p==NULL)
	{
		return q;
	}
	else if(q==NULL)
	{
		return p;
	}
	else
	{
		if(p->degree<=q->degree)
		{
			p->sibling=MERGE(p->sibling,q);
			return p;
		}
		else if(p->degree>q->degree)
		{
			q->sibling=MERGE(q->sibling,p);
			return q;
		}
	}
}

node *CONSOLIDATE(node *p)
{
	if(p==NULL)
		return NULL;
	else if(p->sibling==NULL)
		return p;
	else if(p->sibling->degree>p->degree)
	{
		p->sibling=CONSOLIDATE(p->sibling);
		return p;
	}
	else
	{
		if((p->sibling->sibling!=NULL) && (p->sibling->sibling->degree==p->degree))
		{
			p->sibling=CONSOLIDATE(p->sibling);
			return p;
		}
		if((p->sibling->sibling==NULL) || (p->sibling->sibling->degree>p->degree))
		{
			node *z=p->sibling->sibling;
			if(p->key<p->sibling->key)
			{
				p=BINOMIAL_LINK(p->sibling,p);
				p->sibling=z;
				p=CONSOLIDATE(p);
				return p;
			}
			else
			{
				p=BINOMIAL_LINK(p,p->sibling);
				p->sibling=z;
				p=CONSOLIDATE(p);
				return p;
			}
		}
	}
}


node *MINIMUM(node *H)
{
	node *y=NULL;
	node *x=H;
	int min=INT_MAX;
	while(x!=NULL)
	{
		if(x->key<min)
		{
			min=x->key;
			y=x;
		}
		x=x->sibling;
	}
	return y;
}

node *EXTRACT_MIN(node **H,int n,node* A[])
{
	if(*H==NULL)
		return NULL;
	node *m=MINIMUM(*H);
	delete_node(H,m);
	node *x=m->child;
	node* H2=MAKE_HEAP();
	H2=reverse(x);
	*H=UNION(*H,H2);
	for(int i=0;i<n;i++)
	{
		if(A[i]!=NULL && (A[i]->key==m->key))
		{
			A[i]=NULL;
			break;
		}
	}
	return m;
}

node *DECREASE_KEY(node *H,node *x,int key,int n,node* A[])
{
	int temp;
	int t_i=-1,t_j=-1;
	if(x->key>=key)
	{
		x->key=key;
		node *y=x;
		node *z=y->parent;

		while(z!=NULL && y->key<z->key)
		{
			temp=y->key;
			y->key=z->key;
			z->key=temp;
			y=z;
			z=y->parent;
			for(int i=0;i<n;i++)
			{
				if(A[i]==y)
				{
					t_i=i;
					break;
				}

			}
			for(int i=0;i<n;i++)
			{
				if(A[i]==z)
				{
					t_j=i;
					break;
				}
			}
			if(t_i!=-1)
				A[t_i]=z;
			if(t_j!=-1)
				A[t_j]=y;

		}
	}
	else
	{
		printf("-1\n");
	}
	return H;
}


node *DELETE(node *H,node *x,int n,node* A[])
{
	if(H==NULL)
		printf("-1\n");
	else
	{
		printf("%d\n",x->key);
		H=DECREASE_KEY(H,x,INT_MIN,n,A);
		node *m=EXTRACT_MIN(&H,n,A);
		free(m);
	}
	return H;
}

int num_trees(node *H)
{
	node* temp=H;
	int count=0;
	while(temp!=NULL)
	{
		count++;
	temp=temp->sibling;
	}
	return count;
}


void print(node *H)
{
	if(H==NULL)
		printf("NULL\n");
	else
	{
		node *temp=H;
		while(temp!=NULL)
		{
			printf("%d->",temp->key);
			temp=temp->sibling;
		}
		printf("\n");
	}
}

node *delete_node(node **H,node *m)
{
	node *temp=*H;
	node *prev=NULL;
	if(H==NULL || m==NULL)
		return NULL;
	if(temp->key==m->key)
	{
		//printf("Entered deleted node head\n");
		*H=temp->sibling;
		//free(temp);
	}
	else
	{
		while(temp!=NULL && temp->key!=m->key)
		{
			prev=temp;
			temp=temp->sibling;
		}
		prev->sibling=temp->sibling;
	}
}

node *reverse(node *head)
{
	node *curr=NULL;
	node *prev=NULL;
	node *next=NULL;
	if(head==NULL)
		return head;
	else
	{
		curr=head;
		while(curr!=NULL)
		{
			next=curr->sibling;
			curr->sibling=prev;
			prev=curr;
			curr=next;
		}
		head=prev;
	}
	return head;
}
