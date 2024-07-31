// Circular Queue

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
	if(front==(rear+1)%size)
		printf("Queue is full.\n");
	else{
		int data;
		printf("Enter the number: ");
		scanf("%d",&data);
		if(front==-1 && rear==-1){
			front=rear=0;
			queue[rear]=data;
		}
		else{
			rear=(rear+1)%size;
			queue[rear]=data;
		}
	}
}

void dequeue(){
	if(front==-1 && rear==-1)
		printf("Queue has no data.\n");
	else if(front==rear){
		printf("Dequeued numbner is %d\n",queue[rear]);
		front=rear=-1;
		}
	else{
		printf("Dequed number is %d\n",queue[front]);
		front=(front+1)%size;
	}
}

void display(){
	if(rear==-1 && front==-1)
		printf("Queue has no element.\n");
	else{
		int i=front;
		printf("Queue has these items:- ");
		while(i!=rear){
			printf("%d ",queue[i]);
			i=(i+1)%size;
		}
		printf("%d\n",queue[i]);
}
}
