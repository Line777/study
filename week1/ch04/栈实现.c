#include<stdlib.h>
#include<stdlib.h>
#ifndef _STACK_H
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
int IsEmpty(Stack s);
Stack CreateStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
int Top(Stack s);
void Pop(Stack s);
void Push(int x, Stack s);
struct Node
{
	int Data;
	PtrToNode Next;
 };
#endif
int IsEmpty(Stack s)
{
	return s->Next == NULL;
}
Stack CreateStack(void)
{
	Stack s;
	s = (PtrToNode)malloc(sizeof(struct Node));
	if (s == NULL)
		return;
	s -> Next = NULL;
	MakeEmpty(s);
	return s;
}
void MakeEmpty(Stack s)
{
	if (s == NULL)
	{
		return;
	}
	else
	{
		while (!IsEmpty(s))
			Pop(s);
	}
}
void Push(int x, Stack s)
{
	PtrToNode TmpCell;
	TmpCell =(PtrToNode) malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		return;
	}
	else
	{
		TmpCell->Data = x;
		TmpCell->Next = s->Next;
		s->Next = TmpCell;
	}
}
int Top(Stack s)
{
	if (!IsEmpty(s))
	{
		return s->Next->Data;
	}
	return 0;
}
void Pop(Stack s)
{
	PtrToNode FirstCell;
	if (IsEmpty(s))
	{
		return;
	}
	else
	{
		FirstCell = s->Next;
		s->Next = s->Next->Next;
		free(FirstCell);
	}

}
