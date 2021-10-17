#include<stdlib.h>
#include<stdio.h>
struct TreeNode;
typedef struct TreeNode *PriorityQueue;
PriorityQueue Initialize(void);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2);
#define Insert(X,H)(H=Insert1((X),H))
PriorityQuene Insert1(int X,PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

struct TreeNode
{
    int data;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2)
{
    if(H1==NULL)
    return H2;
    if(H2==NULL)
    return H1;
    if(H1->data<H2->data)
    return Merge1(H1,H2);
    else
    return Merge2(H2,H1);
}
static PriorityQueue Merge1(PriorityQueue H1,PriorityQueue H2)
{
    if(H1->Left==NULL)
       H1->Left=H2;
    else
    {
        H1->Right=Merge(H1->Right,H2);
        if(H1->Left->Npl<H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl=H1->Right->Npl+1;
    }
    return H1;
}
PriorityQuene Insert1(int X,PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode =malloc(sizeof(struct TreeNode));
    SingleNode->data=X;
    SingleNode->Npl=0;
    SingleNode->Left=SingleNode->Right=NULL;
    H=Merge(SingleNode,H);
    return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap,RightHeap;
    if(IsEmpty(H))
    {
        return H;
    }
    LeftHeap=H->Left;
    RightHeap=H->Right;
    free(H);
    return Merge(LeftHeap,RightHeap);
}
