#include<stdio.h>

void heapify(int*,int, int);
void heapsort(int*, int);
void print_array(int*, int);
 
int main()
{
     int n,i;
    int arr[20];
    printf("Enter the number of elements in the array :");
    scanf("%d",&n);
    printf("Enter the elements :\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nArray before sorting:\n");
    print_array(arr, n);
 
    heapsort(arr, n);
 
    printf("\n\nArray after sorting:\n");
    print_array(arr, n);
 
    return 0;
}
 
void heapsort(int* arr, int n)
{
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
 
    for (i = n - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
 
        heapify(arr, i, 0);
    }
}
 
void heapify(int* arr, int n, int i)
{
    int largest = i;
 
    int left = 2 * i + 1;
    int right  = 2 * i + 2;
 
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
 
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
 
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        heapify(arr, n, largest);
    }
}
 
void print_array(int* arr, int n)
{	 int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
