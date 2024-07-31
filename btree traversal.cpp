// binary search tree traversal

// binary search tree formation

// all operations in a binary search tree

#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;    // left pointer for left child and right poiner for right child
};

void preorder(struct node*root);
void inorder(struct node*root);
void postorder(struct node*root);
struct node* insert(struct node*start,int num);
struct node* delete_node(struct node*start,int num);



int main(){
	struct node*root,*gate;
	root=NULL;

	int choice;
		printf("Enter your choice:\n1--Creating a binary search tree\n2--Preorder traversal\n3--Inorder traversal");
		printf("\n4--Postorder traversal\n5--Deleting a node\n0--Exit\n");
		scanf("%d",&choice);
	while(choice!=0){
		if(choice>5)
			printf("Invalid choice!\n");
		switch(choice){
			case 1: int i,j,val;
					printf("Enter the number of nodes:- ");
					scanf("%d",&i);
					for(j=1;j<=i;j++){
					printf("Enter the %d node data:- ",j);
					scanf("%d",&val);
					root=insert(root,val);
									}
					break;
			case 2: if(root==NULL)
						printf("Sorry! No tree is present!\n");
					else{
					printf("Preorder is:-");
					preorder(root);
					printf("\n");
				}
					break;
			case 3:	if(root==NULL)
						printf("Sorry! No tree is present!\n");
					else{
					printf("Inorder is:-");
					inorder(root);
					printf("\n");
				}
					break;
			case 4:	if(root==NULL)
						printf("Sorry! No tree is present!\n");
					else{
					printf("Postorder is:-");
					postorder(root);
					printf("\n");
					}
					break;
			case 5:	if(root==NULL)
						printf("Sorry! No tree is present!\n");
					else{
						int del;
						printf("Enter the data you want to delete: ");
						scanf("%d",&del);
						gate=delete_node(root,del);
						if(gate==0)
							printf("Oops! No data found...\n");
						else{
							root=gate;						
							printf("Deleted %d successfully.\n",del);
						}
						}
					break;
			
		}
		printf("Enter your choice:\n1--Creating a binary search tree\n2--Preorder traversal\n3--Inorder traversal");
		printf("\n4--Postorder traversal\n5--Deleting a node\n0--Exit\n");
		scanf("%d",&choice);
			}
	
	
	return 0;
}




// program for preorder traversal
void preorder(struct node*root){
	if(root==0){
		return ;
	}
		
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

//program for inorder traversal
void inorder(struct node*root){
	if(root==0){
		return ;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

// program for postorder traversal
void postorder(struct node*root){
	if(root==0)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}       

// function of inserting node in binary seach tree when no former tree is present or in a new tree 
struct node* insert(struct node*start,int item){
	struct node*newnode,*prev,*next;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->left=NULL;
	newnode->right=NULL;
	if(start==NULL){
		newnode->data=item;
		return newnode;
	}
	next=start;
	while(next!=0){
		if(next->data>item){
			prev=next;
			next=next->left;
		}
		else{
			prev=next;
			next=next->right;
		}
	}
	newnode->data=item;
	if(item<prev->data)
		prev->left=newnode;
	else
		prev->right=newnode;
	return start;
}                                               

// program for deleting a node in a BST 

struct node* delete_node(struct node*start,int num){
	struct node*bus,*temp,*prev;
	bus=start;
	prev=start;
	while(bus->data!=num && bus!=NULL){
		prev=bus;printf("1\n");
		if(bus->data>num){
			bus=bus->left;
		}
		else
			bus=bus->right;
	}
	if(bus==NULL)
		return 0;
	if(bus->left==NULL && bus->right==NULL){
				printf("3\n");
				if(prev->data>num){
				prev->left=NULL;
				free(bus);
									}
				else{
					prev->right=NULL;
					free(bus);
					}
		}
	else if(prev->left!=0 && prev->right!=0){
		// if the node has both left and right child
		printf("2\n");
		temp=bus->right;
		while(temp->left!=0){
			temp=temp->left;
		}
		if(bus==start){
			temp->left=bus->left;
			return bus->right;
		}
		else
			temp->left=bus->left; 
		if(prev->data>temp->data){
			prev->left=temp;
		}
		else                                                                                                                    
			prev->right=temp;
		free(bus);
	}
	
	else{
		printf("4\n");
			if(bus->right==NULL){
				prev->left=bus->left;
				free(bus);
								}
			else{
				prev->right=bus->right;
				free(bus);
				}
	}

return start;
}

