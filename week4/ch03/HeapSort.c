#include<stdlib.h>
#include<stdio.h>
void PercDown(int A[], int i, int N)
{
	int Child=i;
	int tmp;
	for (tmp = A[i]; Child * 2 + 1 < N; i = Child)
	{
		Child = Child * 2 + 1;
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		if (tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = tmp;
}
void HeapSort(int A[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)
		PercDown(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		int m = A[0];
		A[0] = A[i];
		A[i] = m;
		PercDown(A, 0, i);
	}
}
int main(void)
{
	int A[5] = { 32,43,1,4,54 };
	HeapSort(A, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", A[i]);

	}
	return 0;
}
