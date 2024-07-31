//*****Doubly Circuler linked list***
#include<stdio.h>
#include<malloc.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL,*end=NULL;
int count=0;
struct node *display();
struct node *insert_beg();
struct node *insert_end();
struct node * insert_pos();
struct node * del_beg();
struct node * del_end();
struct node * del_pos();

int main(){
    int choice;
	while(choice!=7){
	printf("\n....Doubly Circuler linked list....\n");
	printf("0.display\n"
		   "1.insert beg\n"
	   	   "2.insert end\n"
	        "3.insert pos\n"
			"4.del beg\n"
			"5.del end\n"
			"6.del pos\n"
			"7.EXIT\n");
	printf("Enter your choice :");
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
	}
}
}
struct node *display(){
    if(count==0)
        printf("EMPTY Linked list !!!!");
    else{
        struct node *temp=head;
        printf("The number of elements are  : %d\n",count);
        while(temp->next != head){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);

    }
}
struct node *insert_beg(){
    struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter the data input :");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=newnode;
        newnode->prev=newnode->next=newnode;
    }
    else {
        struct node *temp=head;
        while(temp->next !=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    count++;
}
struct node *insert_end(){
     struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("ENter the data input :");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=newnode;
        newnode->prev=newnode->next=newnode;
    }
    else {
        struct node *temp=head->prev;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=head;
        head->prev=newnode;
    }
    count++;
}
struct node * insert_pos(){
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
		struct node *temp=head,*temp1;
		for(i=2;i<pos;i++)
			temp=temp->next;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
    newnode->prev=NULL;
	printf("Enter the data :");
	scanf("%d",&newnode->data);
	temp1=temp->next;
	newnode->next=temp1;
	temp1->prev=newnode;
    newnode->prev=temp;
	temp->next=newnode;
	
	count++;
		}
}
struct node * del_beg(){
    if(count==0)
        printf("EMPTY Linked list");
    else {
        struct node *temp=head,*temp1=head;
        while(temp1->next != head){
                temp1=temp1->next;
        }
        head=head->next;
        head->prev=temp1;
        temp1->next=head;
        free(temp);
        count--;
    }
}
struct node * del_end() {
   if(count==0)
        printf("EMPTY Linked list");
    else {
        struct node *temp=head,*temp1;
        while(temp->next != head){
                temp1=temp;
                temp=temp->next;
        }
        temp1->next=head;
        head->prev=temp1;
        free(temp);
        count--;
    } 
}
struct node * del_pos() {
	if(count==0)
		printf("Empty list...");
	else {
		int pos,i;
		printf("Enter the position you want to delete :");
		scanf("%d",&pos); 
		if(pos<1 || pos>count)
			printf("Invalid position...");
		else if(pos==1)
			del_beg();
		else if(pos==count)
			del_end();
		else {
			struct node *temp;
			temp=head;
			for(i=2;i<=pos;i++)	{
				temp=temp->next;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			count--;
		}
	}
}
