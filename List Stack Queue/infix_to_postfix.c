#include<stdio.h>
#include<stdlib.h>

typedef struct stack node;

struct stack
{
	char data;
	node*prev;
};

void push(node**top,char new_element)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=new_element;
	temp->prev=*top;
	*top=temp;
}

char pop(node**stk)
{
	char dat;
	if(*stk==NULL)
		return 'b';
	else
	{
		node*temp=*stk;
		dat=temp->data;
		*stk=temp->prev;
		free(temp);
	}
	return dat;
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

void infixToPostfix(FILE*fread,char*exp)
{
	char scan;int i=0;
	node*top=NULL;
	push(&top,'(');
	int run=1;
	while(1)
	{
		scan=fgetc(fread);
		if(scan=='\n')
		{break;}
		if(scan!='('&&scan!=')'&&scan!='*'&&scan!='/'&&scan!='+'&&scan!='-')	//operand SCANNED
			{exp[i++]=scan;}
		else
			{
			if(scan=='(')
				push(&top,scan);
			else if(scan=='+'||scan=='-'||scan=='*'||scan=='/')
				{
				if(top->data=='(')
				push(&top,scan);
				else if(scan=='+'||scan=='-')//ALWAYS HIGHER OR SAME PRIORITY IN STACK
					{while(top->data!='(')
					exp[i++]=pop(&top);
					push(&top,scan);
					}
				else if(scan=='*')
					{while(top->data=='/'||top->data=='*')//SAME PRIORITY IN STACK
						{
						exp[i++]=pop(&top);
						
						}
						//LOWER PRIORITY IN STACK
						push(&top,scan);
					}
				else if(scan=='/')
					{while(top->data=='*'||top->data=='/')//SAME PRIORITY IN STACK
						{
						exp[i++]=pop(&top);
						
						}
						//LOWER PRIORITY IN STACK
						push(&top,scan);
					}
				}
			else if(scan==')')
				{
				while(top->data!='(')
					{exp[i++]=pop(&top);
					}
					pop(&top);
				}
			}
	}
	
	while(top!=NULL)
	{
		char ch=pop(&top);
		if(ch!='(')
		exp[i++]=ch;
	}
	destroy(top);
}

int main()
{
	FILE*fread,*fwrite;
	
	char sel;int err=0;char exp[100];
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
		sel=fgetc(fread);fgetc(fread);
		switch(sel)
		{
		//PUSH
		case 'e':
			infixToPostfix(fread,exp);
			fprintf(fwrite,"%s\n",exp);
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
