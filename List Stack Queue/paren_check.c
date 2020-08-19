#include<stdio.h>
#include<stdlib.h>

int checkParentheses(char*exp)
{
	char eval[100];int counter=0;
	for(int i=0;exp[i]!='\0';++i)
	{
		if(exp[i]==')'&&counter>0&&eval[counter-1]=='(')
			--counter;
		else if(exp[i]==']'&&counter>0&&eval[counter-1]=='[')
			--counter;
		else if(exp[i]=='}'&&counter>0&&eval[counter-1]=='{')
			--counter;
		else if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
			eval[counter++]=exp[i];
	}
	
	if(counter==0)
		return 1;
	else
		return 0;
}

int main()
{
	FILE*fread,*fwrite;
	char exp[100]; 
	char sel;int err=0,n,new_element;
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
			case 'e':
				fscanf(fread," %s",exp);
				if(checkParentheses(exp))
					fprintf(fwrite,"YES\n");
				else
					fprintf(fwrite,"NO\n");
				break;
			
			case 's':
				err=2;
				break;
			default:
				if(sel!=' '&&sel!='\n')
					printf("Invalid option in input.txt!\n");
		}
	}
	
fclose(fread);
fclose(fwrite);
return 0;
}
