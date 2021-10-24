#include<stdlib.h>
#include<stdio.h>
void ShellSort(int A[], int n)
{
	for (int add = n / 2; add > 0; add = add / 2)
	{
		for (int j = 0; j < add; j++)
		{
			int i = j;
			while (i + add < n)
			{
				if (A[i] > A[i + add])
				{
					int m = A[i];
					A[i] = A[i + add];
					A[i + add] = m;

				}
				i = i + add;
			}
		}
	}
}
int main(void)
{
	int A[5] = { 32,43,1,4,54 };
	ShellSort(A, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", A[i]);

	}
	return 0;
}
