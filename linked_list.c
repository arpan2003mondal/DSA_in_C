#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *newnode,*head=0,*temp,*few;
int count=0,i;
int ch;
//head=NULL;

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
                if(p==0 || p>count)
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
	while(temp!=0){
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
}


//insertion coding part
void insert_beg(){			//function for inserting at beginning
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number you want to insert:- ");
	scanf("%d",&newnode->data);
	if(head==0){
		head=newnode;
		//temp=head;
		newnode->link=NULL;
	}
	else{
		//temp=head;
		newnode->link=head;
		head=newnode;
	}	
	count++;
}

void insert_end(){		//function for inserting number at end position
	if(count==0){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the number you want to insert:- ");
		scanf("%d",&newnode->data);
		head=newnode;
		temp=newnode;
		temp->link=NULL;
	}
	else{
	temp=head;
	while(temp->link!=0){
		temp=temp->link;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the number you want to insert:- ");
		scanf("%d",&newnode->data);
		temp->link=newnode;
		newnode->link=NULL;
	}
	count++;
}
void insert_any(int p){			//function for inserting number at any positio
	temp=head;
	for(i=2;i<p;i++)
		temp=temp->link;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number you want to insert:- ");
	scanf("%d",&newnode->data);
	newnode->link=temp->link;
	temp->link=newnode;
	count++;
}

//deletion coding part
void delete_beg(){		//function for deleting from end position
	if(count==0)
		printf("No element!\n");
	else{
	temp=head;
	if(temp->link==NULL)
			free(temp);

	else{
		head=temp->link;
		free(temp);
	}
	count--;
	//printf("%d\t\t\t\t count--\n ",count);
}
}
void delete_any(int p){		//function for deleting from any position
	few=temp=head;
	if(p<=count){
	for(i=2;i<p+1;i++){
			few=temp;
			temp=temp->link;
	}
	few->link=temp->link;
	free(temp);
	count--;
}
	else
		printf("Position doesn't exists.\n");
}



void delete_end(){			//function for deleting from end position
	if(count==0)
		 printf("No element!\n");
	else{
	temp=head;
	if(temp->link==NULL){
			head=NULL;
			free(temp);
		}	
	else{
	temp=head;	
		while(temp->link!=0){
			few=temp;
			temp=temp->link;
			}
			few->link=NULL;
			free(temp);
		}
	count--;	
}
}
