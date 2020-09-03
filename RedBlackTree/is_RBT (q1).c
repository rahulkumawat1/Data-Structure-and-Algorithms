#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define mem (Node*)malloc(sizeof(Node))


typedef struct node
{
        int data;
        char cl;
        struct node *left, *right;
}Node;

void create(Node **root)
{
        int d;
        char c;
        scanf("%c",&c);
        while(c==')'||c==' ')
                scanf("%c",&c);
        if(c=='(')
        {
                if(scanf("%d",&d))
                {
                        *root = mem;
                        (*root)->data = d;
                        (*root)->left = (*root)->right = NULL;
                        scanf("%c",&c);
                        scanf("%c",&c);
                        (*root)->cl = c;
                        create(&((*root)->left));
                        create(&((*root)->right));
                }
        }
}

int check(Node *root,int min,int max,int *height)
{
        if(!root)
        {
                *height = 1;
                return 1;
        }
        if(root->cl=='R')
        {
                if(root->left)
                if(root->left->cl=='R')
                        return 0;
                if(root->right)
                if(root->right->cl=='R')
                        return 0;
        }
        if(root->data<min || root->data>max)
                return 0;
        int lh=0 , rh = 0,l = 0,r = 0;

        l = check(root->left,min,root->data,&lh) ;
        r = check(root->right,root->data,max,&rh);
        if(root->cl=='B')
                *height = 1 + lh;
        else
                *height = lh;
        if(lh!=rh)
                return 0;
        return l&&r;

}

int isRedBlackTree(Node *root)
{
        if(root && root->cl=='R')
                return 0;
        int height = 0;
        return check(root,INT_MIN,INT_MAX,&height);
}

int main()
{
        Node *root;
        create(&root);
        //print(root);
        printf("%d\n",isRedBlackTree(root));
}

