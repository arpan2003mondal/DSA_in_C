//********insertion sort*********
#include<stdio.h>
void insertion_sort(int a[],int n)	{
	int i,j,key;
	for(i=1;i<n;i++)	{
		j=i-1;
		key=a[i];
		while(j>=0 && a[j]>key)	{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}	
	for(i=0;i<n;i++)	{
		printf("%d\t",a[i]);
	}
}
int main()	{
	int a[20],n,i;
	printf("Enter the number of array elements :");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	for(i=0;i<n;i++)	{
		scanf("%d",&a[i]);
	}
		insertion_sort(a,n);
	
return 0;	
}
