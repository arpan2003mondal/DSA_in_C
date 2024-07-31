#include<stdio.h>
int main()
{
int a[20],n,j,i,temp,flag;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the array elements: ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("The array is:- \n");
for(i=0;i<n;i++)
printf("%d ",a[i]);
//bubble sort---------
for(i=0;i<n-1;i++)
{ flag=0;
for(j=0;j<n-i-1;j++)
{
if(a[j+1]<a[j])
{
//flag=1;
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
flag=1;	
}
}
if(flag==0)
break;
}
printf("\n\nThe sorted array is:-");
for(i=0;i<n;i++)
printf("%d  ",a[i]);
return 0;
}
//}
