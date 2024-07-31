//*********DOUBLE ENDED QUEUE**********
#include<stdio.h>
#define max 6
int deq[max];
int left=-1,right=-1;
void input_r_deq();
void output_r_deq();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display();
int main()	{
	int choice;
	do	{
		printf("\n 1. INPUT RESTRICTED DEQUEUE");
		printf("\n 2. OUTPUT RESTRICTED DEQUEUE");
		printf("\n 3. EXIT");
		printf("\n Enter your choice :");
		scanf("%d",&choice);
		switch(choice)	{
			case 1 :input_r_deq();
						break;
			case 2 :output_r_deq();
						break;
			case 3 :break;
			default : printf("Invalid input !!!");
		}
	}while(choice!=3);
return 0;
}
void input_r_deq()	{
	int choice;
	do	{
		printf("\n *********INPUT RESTRICTED DEQUEUE********");
		printf("\n 1. INSERT FROM RIGHT");
		printf("\n 2. DELETE FROM LEFT");
		printf("\n 3. DELETE FROM RIGHT");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf(" Enter your choice :");
		scanf("%d",&choice);
		switch(choice)	{
			case 1 : insert_right();
						break;
			case 2 : delete_left();
						break;
			case 3 : delete_right();
						break;
			case 4 : display();
						break;
			case 5 : break;
			default :printf("Invalid input !!!");
		}
	}while(choice!=5);
}
void output_r_deq()	{
	int choice;
	do	{
		printf("\n *********OUTPUT RESTRICTED DEQUEUE********");
		printf("\n 1. INSERT FROM RIGHT");
		printf("\n 2. INSERT FROM LEFT");
		printf("\n 3. DELETE FROM LEFT");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf(" Enter your choice :");
		scanf("%d",&choice);
		switch(choice)	{
			case 1 : insert_right();
						break;
			case 2 : insert_left();
						break;
			case 3 : delete_left();
						break;
			case 4 : display();
						break;
			case 5 : break;
			default :printf("Invalid input !!!");
		}
	}while(choice!=5);
}
void insert_left()	{
	if ((left==0 && right==max-1) || (left==right+1))
		printf("OVER FLOW !!!");
	else {
		int val;
		printf("Enter the value :");
		scanf("%d",&val);
		if(left==-1 && right==-1)
			left=right=0;
		else	{
			if(left==0)
				left=max-1;
			else
				left--;
		}
	deq[left]=val;		
	}
}
void insert_right()	{
	int val;
	if((left==0 && right==max-1) || left==right+1)
		printf("OVER FLOW !!!");
	else {
		printf("Enter the value :");
		scanf("%d",&val);
		if(left==-1 && right==-1)		
			left=right=0;
		else if(right==max-1)
			right=0;
		else
			right++;
		deq[right]=val;
	}
}
void delete_left()	{
	if(left==-1 && right==-1)
		printf("UNDER FLOW !!!");
	else{
		if(left==right )
			left=right=-1;
		else if(left==max-1)
			left=0;
		else left++;
	}
}
void delete_right()	{
	if(left==-1 && right==-1)
		printf("UNDER FLOW !!!");
	else {
		if(left==right)
			left=right=-1;
		else {
			if(right==0)
				right=max-1;
			else
				right--;
		}
	}
}
void display()	{
	int i,front=left,rear=right;
	if(front==-1 && rear==-1)
		printf("EMPTY QUEUE !!!	");
	else {
		if(front<=rear)	{
			for(i=front;i<=rear;i++)
				printf("%d\t",deq[i]);
		}
		else{
			for(i=front;i<=max-1;i++)
				printf("%d\t",deq[i]);
			for(i=0;i<=rear;i++)
				printf("%d\t",deq[i]);
		}
	}
}
