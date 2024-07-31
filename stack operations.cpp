#include<stdio.h>
void push();
void pop();
void display();
#define size 5
int stack[size];
int top=-1;
int main(){
	int ch;
do{
	printf("\nEnter your choice:\n1--Push\n2--Pop\n3--Display\n4--Exit\n");
	scanf("%d",&ch);
	if(ch>4)
		printf("Invalid!");
	else{
	switch(ch){
		case 1:	push();
				break;
		case 2:	pop();
				break;
		case 3:	display();
				break;
	}
}
}
while(ch!=4);
return (0);
}

void push(){
	int data;
	if(top==size-1)
		printf("Opertation not possible because of stack overflow.\n");
	else{
		printf("Enter the data:-");
		scanf("%d",&data);
		top++;
		stack[top]=data;
	}
}

void pop(){
	if(top==-1)
		printf("Pop operation not possible because of stack underflow.\n");
	else{
		printf("Poped data is %d",stack[top]);
		top--;
	}
}

void display(){
	int i;
	if(top==-1)
		printf("Stack is empty.\n");
	else{
		printf("Stack data are-- ");
		for(i=top;i>=0;i--)
			printf("%d ",stack[i]);
		}
}
