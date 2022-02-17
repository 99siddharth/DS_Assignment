#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *start=NULL,*end=NULL,*temp_data;
void create_node();
void del_node();
void display_node();

int main()
{
    int choice;
    do
    {
        printf("\nMenu\n 1 create node: ");
        printf("\n2 to delete : ");
        printf("\n 3 Print list : ");
        printf("\n 4 to exit: ");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            create_node();
            break;
            case 2:
            del_node();
            break;
            case 3:
            display_node();
            break;
            case 4:
            return 1;
            default:
            printf("\nEntered choice is invalid :");
        }
    }while(1);
    return 0;
}

void create_node()
{
    node *n_node;
    n_node=(node*)malloc(sizeof(node));
    printf("\nEnter value : ");
    scanf("%d",&n_node->data);
    n_node->next=NULL;
    if(end==NULL)
    start=end=n_node;
    else
    {
        end->next=n_node;
        end=n_node;
    }
    end->next=start;
}

void del_node()
{
    temp_data=start;
    if(start==NULL)
    printf("\nCircular linked list is Underflow :");
    else
    {
        if(start==end)
        {
            printf("\n%d",start->data);
            start=end=NULL;
        }
        else
        {
            printf("\n%d",start->data);
            start=start->next;
            end->next=start;
        }
        temp_data->next=NULL;
        free(temp_data);
    }
}

void display_node()
{
    temp_data=start;
    if(start==NULL)
    printf("\nCircular linked list is Empty");
    else
    {
        printf("\n");
        for(;temp_data!=end;temp_data=temp_data->next)
        printf("\n%d address=%u next=%u\t",temp_data->data,temp_data,temp_data->next);
        printf("\n%d address=%u next=%u\t",temp_data->data,temp_data,temp_data->next);
    }
}