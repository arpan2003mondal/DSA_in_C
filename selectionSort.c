#include <stdio.h>
#include <stdlib.h>
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int *A, int n)
{
    int minIndex;
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&A[i],&A[minIndex]);
    }
}
int main()
{
    int n;
    printf("Enter the number of element you want -\t");
    scanf("%d", &n);
    int *a = (int *)malloc(n*sizeof(int));
    printf("Enter the elements - \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}
