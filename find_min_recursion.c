#include<stdio.h>
int find_min(int min,int start);
void del_min();
int a[10],n,pos;

int main(){
	int ans,i;
	printf("enter the numbers of element: ");
	scanf("%d",&n);
	printf("enter the numbers:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ans=find_min(a[0],1);
	printf("smallest number is %d\n",ans);
	del_min();
	return 0;
}


int find_min(int min,int start){
	
	if(start==n)
		return min;
	else if(min>=a[start]){
		min=a[start];
		pos=start;
		start=start+1;
		return find_min(min,start);
	}
	else{
		start=start+1;
		return find_min(min,start);
	}
	
}

void del_min(){
	int i;
	for(i=pos;i<n;i++){
		a[i]=a[i+1];
	}
	n=n-1;
	printf("after deleting minimum the numbers are: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
