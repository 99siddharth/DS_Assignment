
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *lptr, *rptr;
};


struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->lptr = temp->rptr = NULL;
	return temp;
}


void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->lptr);
		printf("%d, ", root->key);
		inorder(root->rptr);
	}
}


struct node* insert(struct node* node, int key)
{
	
	if (node == NULL)
		return newNode(key);

	
	if (key < node->key)
		node->lptr = insert(node->lptr, key);
	else if (key > node->key)
		node->rptr = insert(node->rptr, key);

	
	return node;
}


int main()
{

	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
    printf("Elements of binary search tree is: 50, 30, 20, 40, 70, 60, 80");
	printf("\nInorder of the binary search: ");
	inorder(root);
  
	return 0;
}
