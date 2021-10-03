#include<stdio.h>
#include<stdlib.h>
/*交换临近结点，不交换数据*/
void SwapData(List L, int a, int b)/*单链表*/
{
	if (a > b)
	{
		int m = a;
		a = b;
		b = m;
	}
	Position P=L;
	for (int i = 0; i < a - 1; i++)
	{
		P = P->Next;
	}
	Position Pmt = P -> Next;
	P->Next = Pmt->Next;
	Pmt->Next = Pmt->Next->Next;
	P->Next->Next = Pmt;
}


struct Position
{
	int Data;
	Position Next;
	Position Previous;
};
void SwapData(List L, int a, int b)/*双链表*/
{
	Position A=L, B;
	if (a > b)
	{
		int m = a;
		a = b;
		b = m;
	}
	for (int i = 0; i < a; i++)
	{
		A = A->Next;
	}
	B = A->Next;
	B->Previous = A->Previous;
	A->Next = B->Next;
	B->Next = A;
	A->Previous = B;
}
