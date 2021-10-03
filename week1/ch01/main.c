#include<stdio.h>
#include<stdlib.h>
#ifndef _List_H     /*宏定义链表*/
struct Node; //声明结点的结构体
typedef struct Node* PtrToNode; /*重命名*/
typedef PtrToNode List;
typedef PtrToNode Position;
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);
void PrintList(List L);

#endif 
struct Node   /*定义结点*/
{
	int Element;
	Position Next;
};
int IsEmpty(List L)/*判断链表为不为空*/
{
	return L->Next == NULL;  /*判断头结点下一个会不会为空*/
}
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
Position Find(int X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;
}
void Delete(int X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}
Position FindPrevious(int X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;

}
void Insert(int X, List L, Position P)
{
	Position TmpCell;
	TmpCell = (Node*)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		printf("Out of space");
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
void PrintList(List L)
{
	Position P = L;
	while (P != NULL)
	{
		printf("%d", P->Element);
		P = P->Next;
	}
}
void DeleteList(List L)
{
	Position P = L;
	
	while (P->Next != NULL)
	{
		Position P1 = P;
		P = P->Next;
		free(P1);
	}
}
