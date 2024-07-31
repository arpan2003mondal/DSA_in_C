#include<stdio.h>
void merge_sort(int a[20],int,int);
void merge(int a[20],int,int,int);
int main()
{
int a[20],n,i;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the array elements: ");
for(i=0;i<n;i++)
 scanf("%d",&a[i]);
printf("The array is -- "); 
for(i=0;i<n;i++)
 printf("%d ",a[i]);
merge_sort(a,0,n-1);
printf("\nAfter sorting the array is:- ");
for(i=0;i<n;i++)
  printf("%d ",a[i]);
return 0;
}

void merge_sort(int a[20],int lb,int ub){
int mid;
if(lb<ub){
 mid=(lb+ub)/2;
 merge_sort(a,lb,mid);
 merge_sort(a,mid+1,ub);
 merge(a,lb,mid,ub); 
}
}

void merge(int a[20],int lb,int mid,int ub){
int b[20],i,j,k;
i=lb;
j=mid+1;
k=lb;
while(i<=mid && j<=ub){
 if(a[i]<=a[j]){
  b[k]=a[i];
  i++;
  k++;
 }
 else{
  b[k]=a[j];
  j++;
  k++;
 }
 
}
if(i>mid){
  while(j<=ub){
   b[k]=a[j];
   j++;
   k++;
 }
}
else{
 while(i<=mid){
 b[k]=a[i];
 i++;
 k++;
 }
}
for(k=lb;k<=ub;k++)
 a[k]=b[k];
}
