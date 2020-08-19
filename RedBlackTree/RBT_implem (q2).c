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

Node *insertRedBlack(Node*,int);

Node *LeftRotation(Node *y)
{
        Node *x = y->right;
        y->right = x->left;
        x->left = y;
        char c = y->cl;
        y->cl = x->cl;
        x->cl = c;
        return x;
}

Node *RightRotation(Node *y)
{
        Node *x = y->left;
        y->left = x->right;
        x->right = y;
        char c = y->cl;
        y->cl = x->cl;
        x->cl = c;
        return x;
}
Node *insertRedBlack(Node *root,int key)
{
        if(!root)
        {
                root = mem;
                root->data = key;
                root->cl = 'R';
                root->left = root->right = NULL;
                return root;
        }
        if(key<root->data)
                root->left = insertRedBlack(root->left,key);
        else
                root->right = insertRedBlack(root->right,key);
        if(root->left && root->left->cl=='R')
        {
                if(root->left->left && root->left->left->cl=='R')
                {
                        if(root->right && root->right->cl=='R')
                        {
                                root->left->cl = 'B';
                                root->right->cl = 'B';
                                root->cl = 'R';
                        }
                        else
                        {
                                root = RightRotation(root);
                        }
                        return root;
                }
                if(root->left->right && root->left->right->cl=='R')
                {
                        if(root->right && root->right->cl=='R')
                        {
                                root->left->cl = 'B';
                                root->right->cl = 'B';
                                root->cl = 'R';
                        }
                        else
                        {
                                root->left = LeftRotation(root->left);
                                root = RightRotation(root);
                        }
                        return root;
                }
        }

        if(root->right && root->right->cl=='R')
        {
                if(root->right->left && root->right->left->cl=='R')
                {
                        if(root->left && root->left->cl=='R')
                        {
                                root->left->cl = 'B';
                                root->right->cl = 'B';
                                root->cl = 'R';
                        }
                        else
                        {
                                root->right = RightRotation(root->right);
                                root = LeftRotation(root);
                        }
                        return root;
                }
                if(root->right->right && root->right->right->cl=='R')
                {
                        if(root->left && root->left->cl=='R')
                        {
                                root->left->cl = 'B';
                                root->right->cl = 'B';
                                root->cl = 'R';
                        }
                        else
                        {
                                root = LeftRotation(root);
                        }
                        return root;
                }
        }
        return root;
}

void print(Node *root)
{
        printf("( ");
        if(root)
        {
                printf("%d %c ",root->data,root->cl);
                print(root->left);
                print(root->right);
        }
        printf(") ");
}

int main()
{
        Node *root = NULL;
        int d;
        char c;
        while(scanf("%d",&d)==1)
        {
                //scanf("%c",&c);
                root = insertRedBlack(root,d);
                root->cl = 'B';
                print(root);
                printf("\n");
        }
}
                                                               

