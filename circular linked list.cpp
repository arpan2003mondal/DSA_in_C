// circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head=0, *newnode, *temp, *last,*temp0;
int count,num,pos;

void insert_beg();
void insert_end();
void insert_pos(int pos);
void delete_beg();
void delete_end();
void delete_pos(int pos);
void print();

int main(){
	int choice;
	do{
		printf("Enter your choice:\n1--Insert beginning\n2--Insert end\n3--Insert any position\n4--Delete beginning\n5--Delete end\n6--Delete any position\n7--Print\n8--Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert_beg();
					break;
			case 2: if(count==0)
						insert_beg();
					else
						insert_end();
				 	break;
			case 3: printf("Enter the position: ");
					scanf("%d",&pos);
					if(pos==1)
						insert_beg();
					else if(pos==count+1)
						insert_end();
					else if(pos==0 || pos>count)
						printf("Invalid Position\n");
					else
						insert_pos(pos);
					break; 
			case 4: if(count==0)
						printf("No data present.\n");
					else
						delete_beg();
					break;
			case 5:if(count==0)
						printf("No data present.\n");
					else if(count==1)
						delete_beg();
					else
						delete_end();
					break;
			case 6: printf("Enter the position: ");
					scanf("%d",&pos);
					if(pos==1)
						delete_beg();
					else if(pos==count)
						delete_end();
					else if(pos==0 || pos>count)
						printf("Invalid Position\n");
					else
						delete_pos(pos);
					break; 			
			case 7: print();
					break;
		}
	}while(choice!=8);
	
	
	
	return 0;
}

void print(){
	if(count==0){
		printf("No data is present.\n");
	}
	else{
		temp=head;
		printf("The linked datas are:--  ");
		while(temp->link!=head){
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("%d\n",temp->data);
	}
}

void insert_beg(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d",&num);
	newnode->data=num;
	if(head==NULL){
		head=newnode;
		last=head;
		newnode->link=head;
	}
	else{
		newnode->link=head;
		last->link=newnode;
		head=newnode;
		
	}
	count++;
}

void insert_end(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d",&num);
	newnode->data=num;
	//temp=last;
	newnode->link=head;
	last->link=newnode;
	last=newnode;
	count++;
}

void insert_pos(int pos){
	int i;
	temp=head;
	for(i=2;i<pos;i++)
		temp=temp->link;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\n");
	scanf("%d",&num);
	newnode->data=num;
	newnode->link=temp->link;
	temp->link=newnode;
	count++;
	//printf("%d ",temp->data);
}

void delete_beg(){
	if(head->link==last){
		head=0;
		printf("Deleted %d\n",last->data);
		free(last);
	}
	else{
		temp=head;
		head=temp->link;
		last->link=head;
		printf("Deleted %d\n",temp->data);
		free(temp);
	}
	count--;
}

void delete_end(){
	temp=head;
		while(temp->link!=head){
			temp0=temp;
		//	printf("%d ",temp->data);
			temp=temp->link;
		}
		temp0->link=head;
		printf("Deleted %d\n",temp->data);
		free(temp);
		count--;
}

void delete_pos(int pos){
	int i;
	temp=head;
	for(i=2;i<pos;i++){
	//	temp0=temp;
		temp=temp->link;
	}
	temp0=temp->link;
	temp->link=temp0->link;
	printf("Deleted %d\n",temp0->data);
		free(temp0);
		count--;
}
