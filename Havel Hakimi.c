#include<stdio.h>
int a[10];
void bubble_sort(int n);
void havel_hakimi(int n);

int main(){
	int i,n;
	printf("Enter the total number of degrees:");
	scanf("%d",&n);
	printf("Enter the degrees: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Entered degrees are: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	bubble_sort(n);
	havel_hakimi(n);	
return 0;
}


void bubble_sort(int n)
{
int i,j,temp;
for(i=1;i<n;i++)
{
for(j=0;j<n-i;j++)
if(a[j+1]<a[j])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;	
}
}
}

void havel_hakimi(int n){
	int i,j,key,k;
	printf("a");
	for(i=0;i<10;i++){
		bubble_sort(n);
		for(j=0;j<n;j++){
			bubble_sort(n);
			key=a[j];
			if(key<n){
			for(k=j+1;k<=key;k++){
				a[k]=a[k]-1;
				if(a[k]==-1){
					printf("Simple graph not possible.\n");
					break;
				}
				//bubble_sort(n)
			}
			}
			else{
				printf("Simple graph not possible\n");
				break;
			}
		}
	}
}
