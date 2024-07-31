 
//bubble_sort
#include<stdio.h>
void bubble_sort(int a[],int n)	{
	int i,j,temp;
	for(i=0;i<n-1;i++)	{
		for(j=0;j<n-1-i;j++)	{
			if (a[j]>a[j+1]) {
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
for(i=0;i<n;i++)	{
	printf("%d\t",a[i]);
}
}

int main()	{
	int a[20],n,i;
	printf("Enter the number of element of the array :");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	for(i=0;i<n;i++)	{
		scanf("%d",&a[i]);
	}
	bubble_sort(a,n);
	return 0;	
}
