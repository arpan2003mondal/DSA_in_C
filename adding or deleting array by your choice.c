//adding or deleting array by your choice
#include<stdio.h>
int a[20],n;
void add_array();
void del_array();

int main()	{
	int i,t;
	printf("Enter the number of array :");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	for(i=0;i<n;i++)	{
		scanf("%d",&a[i]);
	}
	
while(t!=3)	{
printf("1.ADDING AN ARRAY ELEMENT....(PRESS 1)\n2.DELETING AN ARRAY ELEMENT...(PRESS 2)\n3.EXIT...(PRESS 3)\n");
scanf("%d",&t);
switch(t)	{
	case 1:add_array();
			break;
	case 2:del_array();
			break;
}
}
	
return 0;	
}


void add_array()	{
	int e,pos,i;
	printf("Enter the element do you want to add :");
	scanf("%d",&e);
	printf("Enter the position :");
	scanf("%d",&pos);
	pos=pos-1;
	n=n+1;
	for(i=n-1;i>pos-1;i--)	{
		a[i]=a[i-1];
	}
	a[pos]=e;
	printf("Now the number of elements is %d: \n",n);
	printf("Now the array elements are ....\n");
	for(i=0;i<n;i++)	{
		printf("%d\n",a[i]);
	}
}

void del_array()	{
	
	int i,pos;
	printf("Enter the position of element you want to delete :");
	scanf("%d",&pos);
	for(i=(pos-1);i<n-1;i++)	{
		a[i]=a[i+1];
	}
	n--;
	printf("Now the number of elements is %d: \n",n);
	printf("Now the array elements are ....\n");
	for(i=0;i<n;i++)	{
		printf("%d\n",a[i]);
	
}
}

