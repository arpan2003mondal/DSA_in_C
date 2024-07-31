#include<stdio.h>
void binary_search();
int main()	{
	int a[20],i,n;
	printf("Enter the number of array :");
	scanf("%d",&n);
	printf("Enter the array elements :\n");
	for(i=0;i<n;i++)	{
		scanf("%d",&a[i]);
	}
	int sear;
	printf("Enter teh number you want to search :");
	scanf("%d",&sear);
binary_search(a,n,sear);

return 0;
}

//binary_search
void binary_search(int a[],int n,int sear)	{
	int beg,end,mid,i;
	beg=0;  end=n-1;  mid=(beg+end)/2;
	while(beg<=end && a[mid]!=sear)	{
		if(sear>a[mid])	{
			beg=mid+1;
		}
		else	{
			end=mid-1;
		}
		mid=(beg+end)/2;
	}
	if(beg>end) {
		printf("The number is not exists...");
	}
	else
		printf("\nThe position of the element is :%d",mid+1);
	
}
