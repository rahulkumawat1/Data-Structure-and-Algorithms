#include <stdio.h>
#include <stdlib.h>

void enqueue(int Q[], int *front, int *rear, int element, int c, FILE* fp2)
{
    if(((*rear)+1)%c == *front)
    {
        fprintf(fp2,"-999\n");
    }
    else
    {
        if(*front == -1)
            *front = 0;
        *rear = ((*rear)+1)%c;
        Q[*rear] = element;
    }
}

void dequeue(int Q[], int *front, int *rear, int c, FILE* fp2)
{
    if(*front == -1 && *rear == -1)
    {
        fprintf(fp2, "-1\n");
    }
    else if(*front == *rear)
    {
        fprintf(fp2, "%d\n", Q[*front]);
        *front = *rear = -1;
    }
    else
    {
        fprintf(fp2, "%d\n", Q[*front]);
        *front = ((*front)+1)%c;
    }
}

void print(int Q[], int n, int front, int rear, FILE* fp2, int c)
{
    if (front == -1 && rear == -1)
    {
        fprintf(fp2,"-1\n");
        return;
    }
    if (rear >= front)
    {
        if(n==0)
        {
            for(int i = front; i<= rear; i++)
                fprintf(fp2, "%d ", Q[i]);
        }
        else
        {
            for (int i = front; i <= n; i++)
            {
                if(i==rear+1)
                {
                    fprintf(fp2, "END");
                    break;
                }
                fprintf(fp2,"%d ",Q[i]);
                n--;
            }
        }
        fprintf(fp2,"\n");
    }
    else
    {
        if(n==0)
        {
            for (int i = front; i < c; i++)
                fprintf(fp2, "%d ", Q[i]);

            for (int i = 0; i <= rear; i++)
                fprintf(fp2, "%d ", Q[i]);
        }
        else
        {
            for (int i = front; i < n; i++)
            {
                if(i == c)
                    break;
                fprintf(fp2, "%d ", Q[i]);
                n--;
            }

            for (int i = 0; i <=n; i++)
            {
                if(i == rear+1)
                {
                    fprintf(fp2, "END");
                    break;
                }
                fprintf(fp2, "%d ", Q[i]);
                n--;
            }
        }
        fprintf(fp2,"\n");
    }
}


int main()
{
    FILE* fp1 = fopen("input.txt", "r");
    FILE* fp2 = fopen("output.txt", "w");

    int front = -1;
    int rear = -1;
    int c;

    fscanf(fp1, "%d", &c);
    fscanf(fp1, " ");
    int Q[c];

    while(1)
    {
        char choice;
        int element,n;

        fscanf(fp1, "%c", &choice);
        switch(choice)
        {
        case 'e':
            fscanf(fp1, "%d", &element);
            enqueue(Q,&front,&rear, element,c,fp2);
            fscanf(fp1, " ");
            break;
        case 'p':
            fscanf(fp1, "%d", &n);
            print(Q,n,front,rear,fp2,c);
            fscanf(fp1, " ");
            break;
        case 'd':
            dequeue(Q,&front,&rear,c,fp2);
            fscanf(fp1," ");
            break;
        case 's':
            return 0;
        default:
            fprintf(fp2, "-999");
            fclose(fp1);
            fclose(fp2);
        }
    }
    return 0;
}
