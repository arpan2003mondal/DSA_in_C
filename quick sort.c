#include<stdio.h>
int partition_array(int a[20],int,int);
void quick_sort(int a[20],int,int);
int main()
{
int a[20],n,j,i;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the array elements: ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("The array is:- \n");
for(i=0;i<n;i++)
printf("%d ",a[i]);
quick_sort(a,0,n-1);
printf("\nAfter sorting the array is:- ");
for(i=0;i<n;i++)
printf("%d ",a[i]);

return 0;
}







int partition_array(int a[20],int lb,int ub){
int key,start,end,temp;
key=a[lb];
start=lb+1;
end=ub;
while(start<end){
	while(a[start]<=key)
	start++;
	while(a[end]>key)
	end--;
	if(start<end){
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
			}	
	else{
	temp=a[lb];
	a[lb]=a[end];
	a[end]=temp;
}
}
return end;	
}

void quick_sort(int a[20],int lb,int ub){
int i;
	if(lb<ub){
		i=partition_array(a,lb,ub);
	    quick_sort(a,lb,i-1);
		quick_sort(a,i+1,ub);
	}
}

