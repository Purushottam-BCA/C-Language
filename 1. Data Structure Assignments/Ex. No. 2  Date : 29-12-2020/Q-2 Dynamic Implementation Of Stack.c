/* Question :- Write a menu driven program from dynamic implementation of STACK. */
   
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *link;
};

typedef struct Stack STK;

STK *TOP = NULL;

void push(int item);
int pop();
void traverse();
int isEmpty();

int main()
{
    int item,opt,delitem;
    while(1)
    {
        printf("\n\n*********** Dynamic implementation of Stack ************\n");
        printf("\n1. Insert a value \n2. Delete value \n3. Display all values \n4. Exit \n");
        printf("\nEnter your choice : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: //Push
                printf("Enter an item : ");
                scanf("%d",&item);
                push(item);
                break;
            case 2: //Pop
                delitem = pop();
                printf("\nDeleted Data : %d",delitem);
                break;
            case 3: //traverse
                traverse();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option ! Choose valid option");
        } //End of switch
    } //End of while
} // End of main

void push(int item)
{
    STK *temp;
    temp = (STK *)malloc(sizeof(STK));
    temp->data = item;
    if(TOP == NULL)
      temp->link = NULL;
    else
      temp->link = TOP;
    TOP = temp;
    printf("\n%d Insert successfully !",item);
}

int pop()
{
    int delitem;
    if(isEmpty())
        {
            printf("\nStack is empty !! No data available\n");
            return 0;
        }
    else
        {
            STK *temp=TOP;
            delitem = temp->data;
            TOP = temp->link;
            free(temp);
            return delitem;
        }
}

void traverse()
{
    if(isEmpty())
        {
            printf("Stack is empty !! No data available. \n");
            return ;
        }
    STK *temp = TOP;
    printf("\nTotal Elements are : ");
    while (temp->link != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->link;
    }
    printf(" %d ",temp->data); //Last Element
}

int isEmpty()
{
    return TOP==NULL ;
}


/*    Optional here to delete Nodes

void DisposeSTK()
{
   STK *temp = TOP;
   while(temp->link !=NULL)
    {
     TOP = temp->link;
     free(temp);
     temp = temp->link;
    }
} */

