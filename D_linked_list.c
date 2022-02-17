#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

int main()
{
    node *start=NULL,*newnode,*temp,*rn;
    int ch,n,x,c,f;

    do	
    {

        printf("Enter the choice as mentioned\n1. Add\n");
        printf("2. Insert Before\n");
        printf("3. Insert After\n");
        printf("4. Count\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Reverse\n");
        printf("8. Display\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:	
            printf("Enter a number \n");
            scanf("%d",&n);

            newnode=(node*)malloc(sizeof(node));
            newnode->data=n;
            newnode->prev=NULL;
            newnode->next=NULL;

            if(start==NULL)
            {
                start=newnode;		
            }
            else
            {
                rn=start;	


                while(rn->next!=NULL)
                {
                    rn=rn->next;	
                }
            rn->next=newnode;	
            newnode->prev=rn;	
            }
                break;

            case 2:	
            f=0;
            if(start==NULL)
            {
                printf("List is empty\n");
                getch();
            }
            else
            {
                printf("Insert Number \n");
                scanf("%d",&n);
                printf("Insert Before \n");
                scanf("%d",&x);


                newnode=(node*)malloc(sizeof(node));
                newnode->data=n;
                newnode->prev=NULL;
                newnode->next=NULL;
                rn=start;
                while(rn!=NULL)
                {
                    if(start==rn && rn->data==x)	
                    {
                        newnode->next=rn;	
                        rn->prev=newnode;	
                        start=newnode;		
                        f=1;
                        break;
                    }
                    else if(start!=rn && rn->data==x)	
                    {
                        newnode->next=rn;				
                        newnode->prev=rn->prev;			
                        newnode->prev->next=newnode;	
                        rn->prev=newnode;				
                        f=1;
                        break;
                    }
                    rn=rn->next;		
                }
            }
            if(f==0)
            {
                printf("Number not found\n");
                free(newnode);
                getch();	   
            }
            break;

            case 3:
            f=0;
            if(start==NULL)
            {
                printf("List is empty\n");
                getch();	
            }
            else
            {
                printf("Insert Number \n");
                scanf("%d",&n);
                printf("Insert After \n");
                scanf("%d",&x);

                newnode=(node*)malloc(sizeof(node));
                newnode->data=n;
                newnode->prev=NULL;
                newnode->next=NULL;

                rn=start;
                while(rn!=NULL)
                {
                    if(rn->data==x && rn->next==NULL)
                    {
                        newnode->prev=rn;		
                        rn->next=newnode;	
                        f=1;
                        break;
                    }
                    else if(rn->data==x && rn->next!=NULL)	
                    {
                        newnode->next=rn->next;		
                        newnode->next->prev=newnode;	
                        newnode->prev=rn;	
                        rn->next=newnode; 
                        f=1;
                        break;
                    }
                    rn=rn->next;		
                }

                if(f==0)
                {
                    printf("Number not found\n");
                    free(newnode);
                    getch();	
                }
            }
            break;

            case 4:		
            c=0;
            if(start==NULL)
            {
                printf("List is empty\n");
                getch();	
            }
            else
            {

                rn=start;
                while(rn!=NULL)
                {
                    c=c+1;
                    rn=rn->next;	
                }
                printf("Total Nodes = %d\n",c);
                getch();	
            }
            break;

            case 5:	
            f=0;
            c=0;
            if(start==NULL)
            {
                printf("List is empty\n");
                getch();
            }
            else
            {
                printf("Enter Number to Search \n");
                scanf("%d",&x);


                rn=start;
                while(rn!=NULL)
                {
                    c=c+1;		
                    if(rn->data==x)
                    {
                        printf("Number %d Found at Position %d\n",rn->data,c);
                        f=1;
                        break;
                    }
                    rn=rn->next;	
                }

                if(f==0)
                {
                    printf("Number not found\n");
                }
                getch();
            }
            break;

            case 6:		
            f=0;
            if(start==NULL)
            {
                printf("List is empty\n");
                getch();	
            }
            else
            {
                printf("Enter Number to Delete \n");
                scanf("%d",&x);


                rn=start;
                while(rn!=NULL)
                {
                    if(start==rn && rn->data==x)	
                    {
                        start=rn->next;		
                        rn->next->prev=NULL;	
                        free(rn);		
                        f=1;
                        printf("Number Deleted Successfully\n");
                        break;
                    }       
                    else if(rn->next!=NULL && rn->data==x)
                    {
                        rn->prev->next=rn->next;	
                        rn->next->prev=rn->prev;	
                        free(rn);		
                        f=1;
                        printf("Number Deleted Successfully\n");
                        break;
                    }
                    else if(rn->next==NULL && rn->data==x)
                    {
                        rn->prev->next=NULL;
                        free(rn);
                        f=1;
                        printf("Number Deleted Successfully\n");
                        break;
                    }
                    rn=rn->next;		
                }

                if(f==0)
                {
                    printf("Number not found\n");
                }
                getch();
            }
            break;

            case 7:
            if(start==NULL)
            {
                printf("List is empty\n");
                getch();	
            }
            else
            {
                rn=start;		

                while(rn!=NULL)
                {          
                    temp = rn->prev;	
                    rn->prev = rn->next;	
                    rn->next = temp;		
                    rn = rn->prev;		
                }
                start=temp->prev;           

                rn=start;
                while(rn!=NULL)
                {
                    printf("%d ",rn->data);
                    rn=rn->next;
                }
                getch();
            }
            break;

            case 8:	
            if(start==NULL)
            {
                printf("List is empty\n");
                getch();	
            }
            else
            {
                rn=start;	
                while(rn!=NULL)
                {
                    printf("%d \t",rn->data);
                    rn=rn->next;
                }
                getch(); 
            }
            break;

            case 9:
            break;

        }
    }while(ch!=9);
    return 0;
}