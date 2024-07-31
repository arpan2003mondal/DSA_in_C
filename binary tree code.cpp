// binary tree formation

#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;    // left pointer for left child and right poiner for right child
	//struct node*right;
};
struct node*create(); 
//struct node*root,*newnode;

int main(){
	struct node*root;
	root=NULL;
	root=create();
	return 0;
}


struct node*create(){
	int x;
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:[Enter 0 for no data]:\n ");
	scanf("%d",&x);
	if (x==0)
		return 0;
	newnode->data=x;
	printf("Enter the left child:\n");
	newnode->left=create();
	printf("Enter the right child:\n");
	newnode->right=create();
	return newnode;	
}



