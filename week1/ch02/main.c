#include<stdio.h>
#include<stdlib.h>
/*接上题链表*/
int FindData(int k, List L)
{
	Position L1 = L;
	for (int i = 0; i < k; i++)
	{
		if (L1 == NULL)
		{
			printf("Error");
			return;
		}
		else
		{
			L1 = L1->Next;
		}
	}
	return L1->Element;
}
void PrintLots(L, P)
{
	Position  P1 = P;
	while (P1 != NULL)
	{
		int k = P1->Element;
		P1 = P1->Next;
		printf("%d", FindData(k, L));
	}
}
