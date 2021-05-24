/* Q-2. Find a suitable data structure to check whether the given strings are palindrome or not and 
        implement the same. Then insert only the palindromes into a queue.
        
        (ii) Implement the ADTs using Linked List
   
   Ans : STACK will be appropriate Data Structure for this operation because of its recursive nature, 
         since it follows LIFO.
         
   Process :- 1). String  is inserted into Linked list directly then total length of string is calculated.
              2). Then every character of the word is entered into stack through push().
              3). Then Pop( ) is executed and each character is compared with the character stored in linked list. 
              4). If all characters are same (ignoring case) then it is palindrome otherwisenot.
              5). If it is palindrome then it is inserted into Queue.
              6). Memory of linked list is released.    
   
   Note :- This program check whether entered string is palindrome or not with ignorance 
   of Case.So rar = RAR , madaM = mAdAm. if string is palindrome then it is inserted into queue. 

   in this program i have inserted string directly to linked list so when i finish up checking 
   whether string is palindrome or not, i just simply delete the linked list & release the memory. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20	// maximum no. of characters in a word

char UCASE(char ch); // Change Every letter into uppercase

//----------- QUEUE Details -----------

struct Queue
{
   char info[MAX];
   struct Queue *link;
};

typedef struct Queue QUE;

QUE *FRONT = NULL,*REAR = NULL;

void enQueue(char a[],int length);  //Insert only if string is palindrome
void display_Queue();       // Display all strings which are palindrome

// --------- STACK Details ----------

struct Stack
{
    char data;
    struct Stack *link;
};

typedef struct Stack STK;

STK *TOP = NULL; // Initially stack is EMPTY

void push(char item);
char pop();

// ---------- LINKED LIST Details -----------

struct node
    {
     char info[MAX];
     struct node *link;
    };
    
typedef struct node Llist;

Llist *start=NULL; // Initially no Element so start=NULL

void insertLIST();

// Main Program

int main()
{
 char opt;
 int i,choice;
 while(1)
  {
    printf("\n1. Enter a New Word \n2. Display all Palindrome strings in Queue \n3. Exit \n");
    printf("\nEnter Option : ");
    scanf("%d",&choice);
    switch(choice)
     {
        case 1:
            insertLIST();
            break;
        case 2:
            display_Queue();
            break;
        case 3:
            printf("\nThanks for Using Program !!");
            return 0;
            break;
        default:
            printf("\nInvalid Option !!\n");
     } // End of switch
  } // End of while
  return 0;
}// End of main
 
// Change Every letter into Uppercase & return it.
 
char UCASE(char ch)
 {
    if(ch>='a' && ch<='z')
        return (ch-32);
    else
        return ch;
 }
 
 //------------LINKED LIST IMPLEMENTAION---------------
 
void insertLIST()  // Inserting a string into linked list.
{
    char ch;
    int i,strlength=0,flag=1; 
    
    Llist *temp;
    temp=(Llist *)malloc(sizeof(Llist));
    
    printf("\nEnter a word : ");
    scanf("%s",temp->info);  //Since base of string is also constant pointr so '&' is optional here
    
    for(i=0; temp->info[i]!='\0' ; i++) // Findling Length of string
         strlength++;
                
    for(i=0; i<strlength; i++) // Pushing All Characters into stack
        push(temp->info[i]);
            
    for(i=0; i<strlength; i++) // Pop one by one from stack in reverse order & check
        {
            ch=pop();
            if(UCASE(ch) != UCASE(temp->info[i]) )  // Checking with ignoring Case
                flag =0;
        }
                    
    if(flag==0)
        printf("\nENTERED STRING :- [ %s ] IS NOT PALINDROME.\n",temp->info);
    else
        {
        printf("\nENTERED STRING :- [ %s ] IS PALINDROME. ",temp->info);
        enQueue(temp->info,strlength); //Passing values to Queue
        }
    temp = start;             // Now no need of entered string again
    start = NULL;  // So deleting it from Linked List & make it empty.
    free(temp);             // release memory          
}

 //------------STACK IMPLEMENTATION-------------------

void push(char item) //To insert each character in stack
{
    STK *temp;
    temp = (STK *)malloc(sizeof(STK));
    temp->data = item;
    if(TOP == NULL)
      temp->link = NULL;
    else
      temp->link = TOP;
    TOP = temp;
}

char pop()  // For deletion of elements from stack
{
    char delitem;
    if(!(TOP==NULL))
    {
        STK *temp=TOP;
        delitem = temp->data;
        TOP = temp->link;
        free(temp);
        return delitem;
    }
}

//-------------- QUEUE IMPLEMENTATION-------------------

void enQueue(char str[], int length) // Inserting Palindrome string in Queue 
{
    int i;
    QUE *Temp;
   
    Temp = (QUE *)malloc(sizeof(QUE));
    
    for(i=0;i<length; ++i)  // Copying String to the Queue[i]
        Temp->info[i] = str[i];
    
    Temp -> info[i] ='\0';
    Temp -> link = NULL;
   
    if(FRONT==NULL) 		//Check whether it is empty or not
      FRONT = REAR = Temp;
    else
    {
      REAR -> link = Temp;
      REAR = Temp;
    }
   printf("SUCCESSFULLY INSERTED !!!\n");
}

// displaying all elements (strings) of Queue 

void display_Queue( )
{   
    int i;
    if(FRONT==NULL)
     {
      printf("\nQUEUE IS EMPTY !!!\n");
      return;
     }
    else
    {
     QUE *Temp = FRONT;
     printf("\nSTRINGS IN THE QUEUE :- ");
    
     while(Temp->link != NULL)
        {
         printf(" %s ",Temp->info);
         Temp = Temp -> link;
        }
     printf(" %s \n",Temp->info);  // displaying Last string
    }
}

