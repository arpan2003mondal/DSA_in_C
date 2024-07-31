#include<stdio.h>
void enqueue();
void dequeue();
void display();
#define size 5
int queue[size];
int front=-1,rear=-1;

int main(){
	int ch;
	do{
	printf("Enter your choice: \n1-- Inserting Data\n2-- Deleteing Data\n3--Display Data\n4-- Exit\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:enqueue();
				break;
		case 2:dequeue();
				break;		
		case 3:display();
				break;				
	}
	if(ch>4)
		printf("Invalid Choice.\n");
	}
	while(ch!=4);
return 0;
}

void enqueue(){
	if((front==0 && rear==size-1) || front==rear-1 && rear==size-1)
		printf("Queue is full.\n");
	else{
		int item;
		printf("Enter the number: ");
		scanf("%d",&item);
		if(front==-1 && rear==-1){
			front=0;
			rear=0;
			queue[rear]=item;
		}
		else{
			rear++;
			queue[rear]=item;
		}
	}
}

void dequeue(){
    if(front==-1|| front>rear)
		printf("There is no item in the queue.\n");
	else if(front==rear){
		printf("Dequeued element is %d\n",queue[front]);
	//	front=-1;
		//rear=-1;
		front++;
	}	
	else{
		printf("Dequeued element is %d\n",queue[front]);	
		front++;
}
}

void display(){
	if((rear==-1 && front==-1)||front>rear)
		printf("Queue has no element.\n");
	else{
		int i=front;
		printf("Queue has these items:- ");
		while(i<=rear){
			printf("%d ",queue[i]);
			i++;
		}
		printf("\n");
		//printf("%d\n",queue[rear]);
}
}
