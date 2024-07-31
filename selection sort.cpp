#include<stdio.h>
void selection_sort(int [],int);
int main()
{
int a[20],n,i;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the array elements: ");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
printf("The array is-- ");	
for(i=0;i<n;i++)
	printf("%d ",a[i]);
selection_sort(a,n);
printf("\nAfter sorting the array is:- ");
for(i=0;i<n;i++)
 	printf("%d ",a[i]);
return 0;
}

void selection_sort(int a[20],int n){
int i,j,temp,min;
for(i=0;i<n-1;i++){
	min=i;
	for(j=i+1;j<n;j++){
		if(a[j]<a[min])
		min=j;
	}
	if(i!=min){
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
}
