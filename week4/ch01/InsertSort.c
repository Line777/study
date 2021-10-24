#include<stdlib.h>
#include<stdio.h>

void InsertionSort(int A[], int N)
{
    for (int i = 1; i < N; i++)
    {

        for (int j = i; j > 0; j--)
        {
            if (A[j] < A[j - 1])
            {
                int m = A[j];
                A[j] = A[j - 1];
                A[j - 1] = m;
            }

        }

    }
}
int main(void)
{
    int A[5] = { 32,43,1,4,54 };
   InsertionSort(A, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);

    }
    return 0;
}
