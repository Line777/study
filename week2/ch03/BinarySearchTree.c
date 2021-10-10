#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode* Tree;
struct TreeNode{
    int data;
    Tree right;
    Tree left;
};
struct TreeNode* CreateTree(int data)
{
    Tree T=(Tree)malloc(sizeof(struct TreeNode));
    T->data=data;
    T->left=NULL;
    T->right=NULL;
    return T;
}
Tree insert(Tree T,int data)
{
    if(T==NULL)
    {T=(Tree)malloc(sizeof(struct TreeNode));
    if(T==NULL)
    {
        printf("Out of space");
    }
    else
    {
        T->data=data;
        T->left=NULL;
        T->right=NULL;

    }
    }
    else if(data<T->data)
    {
        T->left=insert(T->left,data);
    }
    else if(data>T->data)
    {
        T->right=insert(T->right,data);
    }
    return T;
}
void printTree(Tree T)
{
    if(T!=NULL)
    {
        printf("%d",root->data)
    }
}
void tree2str(struct TreeNode*root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
    }
    if((root->left!=NULL)&&(root->right!=NULL))
{
    printf("(");
    tree2str(root->left);
    printf(")");
     printf("(");
    tree2str(root->right);
    printf(")");
}
else if((root->left!==NULL)&&(root->right==NULL))
{
    printf("(");
    tree2str(root->left);
    printf(")");

}
else if((root->left==NULL)&&(root->right!=NULL))
{
    printf("()");
    printf("(");
    tree2str(root->right);
    printf(")");
}
}
int main(void)
{
    Tree T=CreateTree(6);
    T=insert(T,2);
    T=insert(T,3);
    printTree(T);
    tree2str(T);
    return 0;
}
