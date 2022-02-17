#include<stdio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node *lptr;
	struct node *rptr;

};
void traversal(struct node *T)
{
	if(T!=NULL)
	{
		printf("%c, ",(T->data));
		traversal(T->lptr);
		traversal(T->rptr);
	}

}
void postorder(struct node *T)
{
	if(T!=NULL)
	{
		postorder(T->lptr);
		postorder(T->rptr);
		printf("%c, ",T->data);
	}
}

void main()
{
	struct node *A,*B,*C,*D,*E,*F,*G,*T;
	A=(struct node *)malloc(sizeof(struct node));
	B=(struct node *)malloc(sizeof(struct node));
	C=(struct node *)malloc(sizeof(struct node));
	D=(struct node *)malloc(sizeof(struct node));
	E=(struct node *)malloc(sizeof(struct node));
	F=(struct node *)malloc(sizeof(struct node));
	G=(struct node *)malloc(sizeof(struct node));
	T=A;	
	A->lptr=B;
	B->lptr=C;
	B->rptr=NULL;
	C->lptr=NULL;
	C->rptr=NULL;
	A->rptr=D;
	D->lptr=E;
	D->rptr=G;
	E->lptr=NULL;
	E->rptr=F;
	G->lptr=NULL;
	G->rptr=NULL;
	F->lptr=NULL;
	F->rptr=NULL;
	A->data='A';
	B->data='B';
	C->data='C';
	D->data='D';
	E->data='E';
	F->data='F';
	G->data='G';
	traversal(T);
	printf("\n");
	postorder(T);
}
	
	
	
