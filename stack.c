#include<stdio.h>
#define size 4
int top=-1;
int a[size];
void push(){
	if(top==size-1)
		printf("\nOver flow.....\n");
	else{
		top++;
		printf("Enter the data:");
		scanf("%d",&a[top]);
		printf("\n%d is added...\n",a[top]);
	}
}
void pop(){
	int item;
	if(top==-1)
		printf("\nUnderflow\n");
	else{
		item=a[top];
		top--;
		printf("\n%d deleted.....\n",item);
	}
}
void pick(){
	int i;
	for(i=0;i<=top;i++)
		printf("%d\t",a[i]);
}
int main(){
	int choice;
	while(1){
	printf("\n1.for PUSH press 1\n2.For POP press 2\n3.For PICK press 3\n4.For EXIT press 4\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:push();
			break;
		case 2:pop();
			break;
		case 3:pick();
			break;
		case 4:break;
		default:printf("\ninvalid input....\n");
	}
}
}


