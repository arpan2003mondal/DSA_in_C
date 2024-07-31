#include<stdio.h>
#include<stdlib.h>
#define max 4 
int queue[max];
int front=-1,rear=-1;
void insert();
void delete();
void display();
int main()	{
	int choice,val;
	do {
		printf("\n*****MAIN MENU*****");
		printf("\n 1. insert an element");
		printf("\n 2. delete an element ");
		printf("\n 3. display the queue");
		printf("\n 4. exit");
		printf("\n Enter your choice :");
		scanf("%d",&choice);
		switch(choice)	{
			case 1 :insert();
						break;
			case 2 :delete();
						break;
			case 3 :display();
						break;
			default :printf("INVALID INPUT !!!"); 
		}
	}while(choice!=4);
return 0;	
}
void insert() {
	int val;
	printf("Enter the value to insert :");
	scanf("%d",&val);
	if(rear==max-1)
		printf("Queue OVERFLOW !!!");
	else if(front==-1 && rear==-1)	{
		front=rear=0;
		queue[rear]=val;
	}
	else 	{
		rear++;
	queue[rear]=val;
	}
}
void delete()	{
	if(front==-1 || rear<front) 
		printf("Queue UNDERFLOW !!!");
	else	{
		int val=queue[front];
		front++;
		printf("front element %d id deleted .",val);
	}
}
void display(){
	int i;
	if(front==-1 || rear<front)	
		printf("EMPTY queue !!!");
	else
		 for(i=front;i<=rear;i++)
		 	printf("%d\t",queue[i]);
}
