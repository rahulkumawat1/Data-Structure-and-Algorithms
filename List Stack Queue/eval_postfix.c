#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct stack node;
struct stack
{	int data;
	node*prev;
};

void push(node**top,int new_element)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=new_element;
	temp->prev=*top;
	*top=temp;
}

int pop(node**stk)
{	int num;
	if(*stk==NULL)
		return 'b';
	else
	{
		node*temp=*stk;
		num=temp->data;
		*stk=temp->prev;
		free(temp);
	}
	return num;
}

int scandigit(FILE*fp)
{
	fseek(fp, -2, SEEK_CUR);int num;
	fscanf(fp,"%d",&num);
	return num;
}

void destroy(node*A)
{
	while(A!=NULL)
	{
		node*temp=A;
		A=A->prev;
		free(temp);
	}
}

void evaluatePostfix(FILE*fread,FILE*fwrite)
{
	char scan;int a,b;
	node*top=NULL;
	int run=1;
while(1)
	{if(fgetc(fread)=='\n')
		{break;}
	scan=fgetc(fread);
	if(scan=='-')
	{char t=fgetc(fread);
	if(isdigit(t))	//operand SCANNED
		{
		int number=scandigit(fread);
		push(&top,number);
		continue;
		}
	else
		fseek(fread, -1, SEEK_CUR);
	}	
	if(isdigit(scan))	//operand SCANNED
		{
		int number=scandigit(fread);
		push(&top,number);}
	else				//OPERATOR SCANNED
		{
		if(scan=='*')
			{a=pop(&top);
			b=pop(&top);
			push(&top,a*b);
			}
		else if(scan=='/')
			{a=pop(&top);
			b=pop(&top);
			push(&top,b/a);
			}
		else if(scan=='+')
			{a=pop(&top);
			b=pop(&top);
			push(&top,a+b);
			}
		else if(scan=='-')
			{a=pop(&top);
			b=pop(&top);
			push(&top,b-a);
			}
		}
	}
fprintf(fwrite,"%d\n",pop(&top));
destroy(top);
}

int main()
{
	FILE*fread,*fwrite;
	
	char sel;int err=0;
	fread=fopen("input.txt","r");
	
	if(fread==NULL)
	{
		printf("INPUT FILE ERROR!");
		return 0;
	}
	fwrite=fopen("output.txt","w");
	if(fread==NULL)
	{	
		printf("OUTPUT FILE ERROR!");
		return 0;
	}
	while(err==0)
	{	
		sel=fgetc(fread);
		switch(sel)
		{
		//PUSH
			case 'e':
				evaluatePostfix(fread,fwrite);
				break;
			
			case 's':
				err=2;
				break;
			
			default:
				if(sel==EOF)
					err=3;
				if(sel!=' '&&sel!='\n')
					printf("Invalid option in input.txt!\n");
		}
	}
fclose(fread);
fclose(fwrite);
return 0;
}
