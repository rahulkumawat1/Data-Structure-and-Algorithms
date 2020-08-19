#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mem (Node*)malloc(sizeof(Node))

typedef struct node
{
	char *word;
	struct node *next;
}Node;

int hashCode(char word[],int cap)
{
	return strlen(word)%cap;
}

void groupWords(char sent[],int cap)
{
	Node *head[cap];
	for(int i=0;i<cap;i++)
		head[i] = NULL;
	int index,k=0,l;
	char s[50];
	Node *temp,*temp1,*temp2;
	int flag = 0;
	while(1)
	{
	    l = 0;
	while(sent[k]!=' ')
        {
            if(sent[k]=='.')
            {
                flag = 1;
                break;
            }
            if((sent[k]>='a' && sent[k]<='z') || (sent[k]>='A' && sent[k]<='Z'))
                s[l++] = sent[k++];
            else
                k++;
        }
        if(l==0)
        {
            if(flag)
            break;
            k++;
            continue;
        }
        s[l] = '\0';
        k++;
		index = hashCode(s,cap);
		temp = head[index];
		if(!temp)
		{
			head[index] = mem;
			head[index]->word = (char*)malloc(l+1);
			strcpy(head[index]->word,s);
			head[index]->next = NULL;
		}
		else
		{
			while(temp)
			{
				if(!strcmp(s,temp->word))
					break;
				temp2 = temp;
				temp = temp->next;
			}
			if(!temp)
			{
			temp1 = mem;
			temp1->word = (char*)malloc(l+1);
			strcpy(temp1->word,s);
			temp1->next = NULL;
			temp2->next = temp1;
			}
		}
		if(flag)
			break;
	}
	for(int i=0;i<cap;i++)
	{
		if(head[i]==NULL)
			printf("NULL");
		else
		{
			temp = head[i];
			while(temp)
			{
				printf("%s ",temp->word);
				temp = temp->next;
			}
		}
		printf("\n");

	}

}

int main()
{
	int cap;
	scanf("%d",&cap);
	scanf("\n");
	char sent[500];
	scanf("%[^\n]s",sent);
	groupWords(sent,cap);
}
