// Name :- PURUSHOTTAM KUMAR (2041)
// Program to implement single linked list

#include<stdio.h>
#include<malloc.h>

struct node
    {
    int info;
    struct node *link;
    };
    
typedef struct node Llist;

Llist *start=NULL,*end=NULL; //Initially no Element

int isempty() //To check whether linked list is empty or not.
{
    if(start==NULL)
        return 1;
    else
        return 0;
}

void create(int data)
{
    Llist *new;
    new = (Llist *)malloc(sizeof(Llist));
    new->info = data;
    new->link = NULL ; 
    if(isempty())
        start = end = new; //All points to same node
    else
    {
        new->link = start;
        start =new;
    }
    printf("\nNode [value - %d] Successfully Inserted !!\n",data);
}

void display()
{   
    if(!isempty()) //If list is not empty
    {
        Llist *temp;
        temp = start;
        printf("\nElements of Lined List : ");
        while(temp)
        {
            printf(" %d ",temp->info);
            temp=temp->link;
        }
    }
    else
        printf("\nList is empty ! Nothing to display\n");
}

void insertfirst(int data)
{
    Llist *temp;
    temp=(Llist *)malloc(sizeof(Llist));
    temp->info = data;
    temp->link=start;
    if(isempty())
        start=end=temp;
    else
        start=temp;
    printf("\nNode [value - %d] Successfully Inserted !!\n",data);
}

void insertlast(int data) // Insert at last position 
{
    Llist *temp,*temp2=start;
    temp=(Llist *)malloc(sizeof(Llist));
    if(isempty()) // if list is empty
    {
        temp->link=NULL;
        start=end=temp;
    }
    else  // if list is not empty 
    {
        while(temp2->link !=NULL)
            temp2 =temp2->link;
        temp->link= NULL;
        temp2->link=temp;
    }
    printf("\nNode [value - %d] Successfully Inserted !!\n",data);
}

void deleteFnode()     //Deleting First Node
{
    int delitem;
    Llist *temp=start;
    if(isempty())
        printf("Nothing to delete ! List is empty \n");
    else
    {
      delitem = temp->info;
      start= temp->link;
      free(temp);
      printf("\nDeleted Item : %d\n",delitem);
    }
}

int main()
{
    create(10);
    insertfirst(15);
    insertlast(34);
    insertfirst(25);
    display();
    deleteFnode();
    display();
}
