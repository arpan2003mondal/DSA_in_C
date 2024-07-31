 // .............Singly linked list..........
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*newnode;
int count=0;
void display(){
	if(count==0)
		printf("Empty list....");
	else	{
		printf("Number of elements are %d\n",count);
		struct node*temp;
		temp=head;
		while(temp!=NULL)	{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void insert_beg(){						//insert at the begining
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the data :");
	scanf("%d",&newnode->data);
	if(count==0)
		head=newnode;
	else	{
		newnode->next=head;
		head=newnode;
	}
count++;		
}
void insert_end(){
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the data :");
	scanf("%d",&newnode->data);
	struct node *temp;
	if(count==0)
		head=temp=newnode;
	else	{
		temp=head;
		while(temp->next!=NULL)	{
			temp=temp->next;
		}
			temp->next=newnode;
	}
count++;
}
void insert_pos() {
	int pos,i;
	printf("Enter the position :");
	scanf("%d",&pos);
	if(pos<1 || pos>count+1)
		printf("Invalid position.....");
	else if(pos==1)
		insert_beg();
	else if(pos==count+1)
		insert_end();			
	else   {
		struct node *temp=head;
		for(i=2;i<=pos;i++)
			temp=temp->next;
		newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the data :");
	scanf("%d",&newnode->data);
	newnode->next=temp->next;
	temp->next=newnode;
	count++;
		}
}
void del_beg(){
	if(count==0)
		printf("Empty list.....");
	else	{
		struct node *temp;
		temp=head;
		head=head->next;
		free(temp);
		count--;
	}
}
void del_end(){
	if(count==0)
		printf("Empty list....");
	else {
		struct node *temp=head,*temp1;
		while(temp->next!=NULL)	{
			temp1=temp;
			temp=temp->next;
	}
	temp1->next=NULL;
	free(temp);
	count--;	
	}
}
void del_pos(){
	if(count==0)
		printf("Empty list...");
	else {
	int pos;
	printf("Enter the positon :");
	scanf("%d",&pos);
	if(pos<1|| pos>count)
			printf("Invalid position...");
	else if(pos==1)
		del_beg();
	else if(pos==count)
		del_end();
	else if(pos>1 || pos<count){
	int i;
	struct node *temp=head,*temp1;
		
		for(i=2;i<=pos;i++){
		temp1=temp;
		temp=temp->next;
		}
	temp1->next=temp->next;
	free(temp);
	}
	count--;
	}
}
int main(){
	int choice;
	while(choice!=7){
	printf("\n....linked list....\n");
	printf("0.display\n"
		   "1.insert beg\n"
	   	   "2.insert end\n"
	        "3.insert pos\n"
			"4.del beg\n"
			"5.del end\n"
			"6.del pos\n"
			"7.EXIT\n");
	scanf("%d",&choice);
	switch(choice){
		case 0:display();
				break;
		case 1:insert_beg();
				break;
		case 2:insert_end();
				break;
		case 3:insert_pos();
				break;
		case 4:del_beg();
				break;
		case 5:del_end();
				break;
		case 6:del_pos();
				break;
		case 7:break;
		default :printf("invalid input...");
	}
}	
return 0;	
}

