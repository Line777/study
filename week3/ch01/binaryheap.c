#include<stdlib.h>
#include<stdio.h>
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
PriorityQueue Initialize(int Maxdata);
void Insert(int X,PriorityQueue H);
int DeleteMin(PriorityQueue H);
int FindMin(PriorityQuene H);
int IsEmpty(PriorityQuene H);
int IsFull(PriorityQune H);
struct HeapStruct
{
    int Capacity;
    int Size;
    int *data;
};

PriorityQueue Initialize(int Maxdata)
{
    PriorityQueue H;
    H=malloc(sizeof(struct HeapStruct));
    if(H->data==NULL)
    {
        printf("error");
    }
    H->Capacity=Maxdata;
    H->Size=0;
    H->data[0]=MinData;
    return H;
    
}
void Insert(int X,PriorityQueue H)
{
    int i;
    if(IsFull(H))
    {
        return;
    }
    for(i=++H->Size;H->data[i/2]>X;i/=2)
    {
        H->data[i]=H->data[i/2];
        
    }
    H->data[i]=X;
}
int DeleteMin(PriorityQueue H)
{
    int i,Child;
    int Mindata,Lastdata;
    if(IsEmpty(H))
    {
        return H->data[0];
    }
    Mindata=H->data[1];
    Lastdata=H->data[H->Size--];
    for(i=1;i*2<=H->Size;i=Child)
    {
        Child=i*2;
        if(Child!=H->Size&&H->data[Child+1]<H->data[Child])
        {
            Child++;
        }
        if(Lastdata>H->data[Child])
          H->data[i]=H->data[Child];
          else
          break;

    }
    H->data[i]=Lastdata;
    return Mindata;
}
int FindMin(PriorityQuene H)
{
    if(IsEmpty==1)
    {
        return ;
    }
    return H->data[1];
}
int IsEmpty(PriorityQuene H)
{
    if(H->Size==0)
    {
        return 1;
    }
    return 0;
}
int IsFull(PriorityQune H)
{
    if(H->Size==H->Capacity)
{
    return 1;
}
   return 0;
}
