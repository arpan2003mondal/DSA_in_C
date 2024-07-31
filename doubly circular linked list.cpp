#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
	//struct node *last;
};
struct node *newnode,*head,*temp,*few,*last;
int count=0,i;
int ch;

void insert_beg();
void insert_end();
void insert_any(int);
void delete_beg();
void delete_end();
void delete_any(int);
void print_list();

int main(){
	int choice=0,p;
	head=temp=0;

printf("Enter your choice:\n1--Insert beginning\n2--Insert end\n3--Insert any\n4--Delete beginning\n5--Delete end\n6--Delete any\n7--Print\n8--Exit\n");
scanf("%d",&ch);
while(ch!=8){
switch(ch){
        case 1: insert_beg();
                break;
        case 2: insert_end();
                break;
        case 3: printf("Enter the position: ");
                scanf("%d",&p);
                if(p==0 || p>=count+2)
                	printf("Position doesn't exists.\n");
                else if(p==1)
                	insert_beg();
                else if(p==count+1)
					insert_end();	
                else	
                insert_any(p);
                break;
        case 4: delete_beg();
                break;
        case 5: delete_end();
                break;
        case 6:	if(count==0)
        			printf("No element!\n");
        		else{
				printf("Enter the position you want to delete: ");
                scanf("%d",&p);
                if(p<=0 || p>count)
                	printf("Position doesn't exists.\n");
                else if(p==1)
                	delete_beg();
                else if(p==count)
				delete_end();
                else
                delete_any(p);
            	}
				break;

        case 7: print_list();
                break;
}
printf("Enter your choice:\n1--Insert beginning\n2--Insert end\n3--Insert any\n4--Delete beginning\n5--Delete end\n6--Delete any\n7--Print\n8--Exit\n");
scanf("%d",&ch);
}

return 0;
}


void print_list(){        //for printing linked list
	if(count==0)
		printf("No element Present.\n");
	else{
	temp=head;
	printf("The numbers are:-");
	while(temp->next!=head){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d ",temp->data);
	printf("\n");
}
}


//insertion coding part
void insert_beg(){			//function for inserting at beginning
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number you want to insert:- ");
	scanf("%d",&newnode->data);
	//newnode->prev=NULL;
	//newnode->next=NULL;
	if(count==0){
		head=last=newnode;
		newnode->prev=head;
		last->next=newnode;
	}
	else{
	head->prev=newnode;
	//head->next=newnode;
	newnode->next=head;
	newnode->prev=last;
	last->next=newnode;
	head=newnode;
	}
	count++;
}

void insert_end(){		//function for inserting number at end position
	if(count==0){
		insert_beg();
	}
	else{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the number you want to insert:- ");
		scanf("%d",&newnode->data);
		last->next=newnode;
		newnode->prev=last;
		newnode->next=head;
		head->prev=newnode;
		last=newnode;
	}
	count++;
}
void insert_any(int p){			//function for inserting number at any position
	temp=head;
	for(i=1;i<p-1;i++)
		temp=temp->next;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number you want to insert:- ");
	scanf("%d",&newnode->data);
	newnode->next=temp->next;
	temp->next->prev=newnode;
	newnode->prev=temp;
	temp->next=newnode;
	count++;
}

//deletion coding part
void delete_beg(){		//function for deleting from end position
	if(count==0)
		printf("No element!\n");
	else{
	temp=head;
	if(temp->next==head){
			head=NULL;
			free(temp);
	}
	else{
		head=temp->next;
		head->prev=last;
		last->next=head;
		free(temp);
	}
	count--;
	//printf("%d\t\t\t\t count--\n ",count);
}
}
void delete_any(int p){		//function for deleting from any position
	temp=head;
	for(i=2;i<=p;i++){
			temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
	count--;
}


void delete_end(){			//function for deleting from end position
	if(count==0)
		 printf("No element!\n");
	else{
	temp=head;
	if(temp->next==head){
			head=NULL;
			free(temp);
		}
	else{
		last=last->prev;
		last->next=head;
		head->prev=last;
		}
	count--;
}
}

