#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexofMin, temp;
    printf("Running selection sort ....\n");
    for (int i = 0; i < n - 1; i++)
    {
         indexofMin = i;
        for (int j = i + 1; j < n; j++)
        {

            if (A[j] < A[indexofMin])
            {
                indexofMin = j;
            }
        }
       //swap A[i] and A[IndexofMin]
        temp = A[i];
        A[i] = A[indexofMin];
        A[indexofMin] = temp;
    }
}
int main()
{

    //Input Array(There will be total n-1 passes. i.e 4 in this case
    // 1  2  3  4  5
    // 02 05 01 03 04

    //After first pass
    // 1  2  3  4  5
    // 01 05 02 03 04

    //After second pass
    // 1  2  3  4  5
    // 01 02 05 03 04

    //After second pass
    // 1  2  3  4  5
    // 01 02 03 05 04

    //After fourth pass
    // 1  2  3  4  5
    // 01 02 03 04 05

    int A[] = {2, 5, 1, 3, 4};
    int n = 5;

     printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}