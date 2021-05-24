// Write a menu driven program from dynamic implementation of QUEUE. 

#include<stdio.h>
#include<stdlib.h>

struct Queue
    {
    int data;
    struct Queue *link;
    };
    
typedef struct Queue QUE;
QUE *FRONT = NULL,*REAR = NULL;

void enQueue(int);
int deQueue();
void traverse();
int isEmpty();

void main()
{
    int item,opt,delitem;
    while(1)
    {
        printf("\n\n*********** Dynamic implementation of Queue ************\n");
        printf("\n1. Insert a value \n2. Delete value \n3. Display all values \n4. Exit ");
        printf("\nEnter your choice : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: //Inserting Value
                printf("\nEnter an item : ");
                scanf("%d",&item);
                enQueue(item);
            break;
            case 2: //Deletion
                delitem = deQueue();
                printf("\nDeleted Data : %d",delitem);
                break;
            case 3: //traverse
                traverse();
                break;
            case 4:
                return;
                break;
            default:
                printf("Invalid option ! Choose valid option");
        } //End of switch
    } //End of while
} // End of main

// Inserting value inQueue 
void enQueue(int item)
{
    QUE *Temp;
    Temp = (QUE *)malloc(sizeof(QUE));
    Temp->data = item;
    Temp -> link = NULL;
    if(isEmpty()) //Check whether it is empty or not
        FRONT = REAR = Temp;
    else
    {
        REAR -> link = Temp;
        REAR = Temp;
    }
    printf("\n%d Successfully Inserted !!!\n",item);
}
// Deleting value from Queue 
int deQueue()
{
    int delitem;
    if(isEmpty())
    {
        printf("\nQueue is Empty!!!\n");
        return 0;
    }
    else
    {
        QUE *Temp = FRONT;
        delitem = Temp -> data;
        FRONT = FRONT -> link;
        free(Temp);
        return delitem;
    }
}

// Checking whether Queue is empty or not
int isEmpty()
{
    return FRONT==NULL;
}

// Traversing all elements (nodes) of Queue 
void traverse()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty !!!\n");
        return;
    }
    else
    {
        QUE *Temp = FRONT;
        while(Temp->link != NULL)
        {
            printf(" %d ",Temp->data);
            Temp = Temp -> link;
        }
        printf(" %d \n",Temp->data);
    }
}
