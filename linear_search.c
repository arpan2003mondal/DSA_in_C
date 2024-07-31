//linear_search
#include<stdio.h>

int linear(int a[],int n,int p)	{
	int i;
	for(i=0;i<n;i++)	{
		if(a[i]==p)
			return i+1;
	}
	return -1;
}

int main()	{
	int f,i;
	int a[20],n,p;
	printf("Enter the number of elements(n) :");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("Enter the element do you want to search :");
	scanf("%d",&p);
	
	f=linear(a,n,p);
	if(f==-1)	{
		printf("There is no such that numbner...");
	}
	else	{
		printf("The position of this number is %d",f);
		}
	
return 0;	
}
