//linear search
#include<stdio.h>
int linear_search(int [],int,int);
void print_array(int [],int);
int main()
{
int a[20],i,n,num;
printf("Enter the number of elements of the array:");
scanf("%d",&n);
printf("Enter the elements of the array:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
print_array(a,n);
printf("\nEnter the element you want to find: ");
scanf("%d",&num);
int p=linear_search(a,n,num);
if(p==-1)
printf("%d is not present!",num);
else
if(p<n)
printf("%d is present at position %d",num,p+1);
return 0;
}

void print_array(int a[],int n)      //array printing
{
int i;
printf("The array is : ");
for(i=0;i<n;i++)
printf("%d ",a[i]);	
}

int linear_search(int a[20],int n,int num)
{
int i;
for(i=0;i<n;i++){
if(a[i]==num)
return i;
}
return -1;

}

