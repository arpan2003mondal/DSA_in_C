#include<stdio.h>
void enqueueRear();
void enqueueFront();
void dequeueRear();
void dequeueFront();
void display();
#define size 5
int dqueue[size];
int front=-1,rear=-1,count=0;
//front=-1;
//rear=-1;
//count=0;

int main(){
	int choice;
	do{
		printf("Enter your choice:\n1--Insert end\n2--Insert beg\n3--Delete beg\n4--Delete end\n5--Display\n6--Exit\n");
		scanf("%d",&choice);
		if(choice<7||choice==0){
		switch(choice){
			case 1: if(count==size)
						printf("Queue is full.\n");
					else	
						enqueueRear();
					break;
			case 2: if(count==size)
						printf("Queue is full.\n");
					else
						enqueueFront();
					break;
			case 3: if(count==0)
						printf("Queue is empty.\n");
					else
						dequeueFront();
					break;
			case 4: if(count==0)
						printf("Queue is empty.\n");
					else
						dequeueRear();
					break;					
			case 5: display();
					break;					
		}
	}
	else
		printf("Invalid Choice!\n");
	}while(choice!=6);
	return 0;
}

// insert from end function
void enqueueRear(){
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
	/*if((front==0 && rear==size-1)|| front==rear+1)
		printf("Queue is full.\n");
	else*/ if(front==-1 && rear==-1){
		front=rear=0;
		dqueue[rear]=data;
		count++;
		}
	else{
		rear=(rear+1)%size;
		dqueue[rear]=data;
		count++;
	}	
}

// insert from beg function
void enqueueFront(){
	int data;
	printf("Enter data: ");
	scanf("%d",&data);
/*	if((front==0 && rear==size-1)|| front==rear+1)
		printf("Queue full\n");
	else*/ if(front==-1 && rear==-1){
		front=rear=0;
		dqueue[front]=data;
		count++;
		}
	else if(front==0){
		front=size-1;
		dqueue[front]=data;
		count++;
	}
	else{
		front--;
		dqueue[front]=data;
		count++;
	}
}

// delete from beg function
void dequeueFront(){
	/*if(front==-1 && rear==-1 )
		printf("Queue is empty\n");
	else */if(front==rear){
		printf("Deleted %d\n",dqueue[front]);
		front=rear=-1;
		count--;
	}
	else{
		printf("Deleted %d\n",dqueue[front]);
		front=(front+1)%size;
		count--;
	}
}

// delete from end function
void dequeueRear(){
	/*if(front==-1 && rear==-1)
		printf("Queue is empty\n");
	else*/ if(front==rear){
		printf("Deleted %d\n",dqueue[rear]);
		front=rear=-1;
		count--;
	}
	else if(rear==0){
		printf("Deleted %d\n",dqueue[rear]);
		rear=size-1;
		count--;
	}
	else{
		printf("Deleted %d\n",dqueue[rear]);
		rear--;
		count--;
	}
}

// function for display
void display(){
	if(rear==-1 && front==-1)// or if(count==0)
		printf("Queue has no element.\n");
	else{
		int i=front;
		printf("Queue has these items:- ");
		while(i!=rear){
			printf("%d ",dqueue[i]);
			i=(i+1)%size;
		}
		printf("%d\n",dqueue[i]);
}
}
