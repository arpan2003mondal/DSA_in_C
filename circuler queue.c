#include<stdio.h>
#include<conio.h>
#define max 6
int cirq[max];
int rear=-1,front=-1;
void insert();
void delete();
void display();
int main()	{
	int choice;
	do	{
	printf("\n***MAIN MENU***");
	printf("\n 1. INSERT");
	printf("\n 2. DELETE");
	printf("\n 3. DISPLAY");
	printf("\n 4. EXIT");
	printf("\n Please enter your choice :");
	scanf("%d",&choice);
	switch(choice)	{
		case 1 : insert();
				break;
		case 2 : delete();
				break;
		case 3 : display();
				break;
		case 4 : break;
		default :printf("\nInvalid input !!!\n");
	}
	}while(choice!=4);
return 0;	
}
void insert()	{
	int val;
	if((front==0 && rear==max-1) || front==rear+1)
		printf("OVER FLOW !!!");
	else {
		printf("Enter the value :");
		scanf("%d",&val);
		if(front==-1 && rear==-1)		
			front=rear=0;
		else if(front!=0 && rear==max-1)
			rear=0;
		else
			rear++;
		cirq[rear]=val;
	}
}
void delete()	{
	if(front==-1 && rear==-1)
		printf("UNDER FLOW !!!");
	else{
		if(front==rear )
			front=rear=-1;
		else if(front==max-1)
			front=0;
		else front++;
	}
}
void display()	{
	int i;
	if(front==-1 && rear==-1)
		printf("EMPTY QUEUE !!!	");
	else {
		if(front<=rear)	{
			for(i=front;i<=rear;i++)
				printf("%d\t",cirq[i]);
		}
		else{
			for(i=front;i<=max-1;i++)
				printf("%d\t",cirq[i]);
			for(i=0;i<=rear;i++)
				printf("%d\t",cirq[i]);
		}
	}
}
