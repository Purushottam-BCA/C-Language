/* Q-1. Find a suitable data structure to check whether the given strings are palindrome or not and 
        implement the same. Then insert only the palindromes into a queue.
        (i) Implement the ADTs using array
        
   Ans : STACK will be appropriate DS for this operation because of its recursive nature, since it follows LIFO.
   
         Explanation : This program check entered string whether it is palindrome or not with ignorance of Case 
         means raR is also palindrome. if string is palindrome then it is inserted into queue. */

#include <stdio.h>
#include <string.h>

#define MAX 20	// maximum no. of characters //

char UCASE(char ch); // Change Every letter into uppercase

//-----------Queue-----------

char Queue[50][MAX];  // Creating Array of String
int front=-1, rear=-1; 

void enQueue(char a[],int length);  //Insert only if tring is palindrome
void display_Queue();       // Display all strings which are palindrome

//----------Stack----------

char stack[MAX];
int TOP =-1;
int item;

void push(char item);
char pop(void);

int isEmpty(void);
int isFull(void);
 
//----------- Main Function -------------- 

int main()
{
 char opt,str[MAX],RevSTR[MAX];
 int i,length,flag,choice;
 while(1)
  {
    length=0;
    flag=1;  
    printf("\n1. Enter a new word \n2. Display all palindrome strings in Queue \n3. Exit \n");
    printf("\nEnter Option : ");
    scanf("%d",&choice);
    switch(choice)
     {
        case 1:
                printf("\nEnter a word : ");
                scanf("%s",str);          
    
                for (i = 0; str[i] != '\0'; i++) //Finding length of String
                    length++;
    
                for(i=0; i<length; i++) //Pushing All Characters into stack
                    push(str[i]);
            
                for(i=0; i<length; i++) //Pop one by one into second array
                    RevSTR[i]=pop();
            
                RevSTR[i]='\0';  // Assigning NULL at last of string
   
                for(i=0; i<length ;i++)
                    if(UCASE(str[i]) != UCASE(RevSTR[i]) )
                        flag =0;
                
                if(flag==0)
                    printf("\n%s is not palindrome.\n",str);
                else
                    {
                    printf("\n[ %s ] is palindrome. ",str);
                    enQueue(str,length);
                    }   
                break;
            case 2:
                display_Queue();
                break;
            case 3:
                return 0;
                break;
            default:
                printf("\nInvalid Option !!\n");
     } // End of switch
  } // End of while
  return 0;
}
 
 // Change Every letter into Uppercase & return it.
 
char UCASE(char ch)
 {
    char temp;
    if(ch>='a' && ch<='z')
    {
        temp= ch-32;
        return temp;
    }
    else
        return ch;
 }
 
 //------------Stack Operations-------------------
void push(char item) // For insertion
{
    if(isFull())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    TOP = TOP + 1;
    stack[TOP] =item;
}
 
char pop()  // for deletion
{
    if(isEmpty())
    {
        printf("\nStack is EMPTY !!!\n");
        return '0';
    }
    item = stack[TOP];
    TOP = TOP-1;
    return item;
}
 
int isEmpty()
{
    if(TOP == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(TOP==MAX-1)
        return 1;
    else
        return 0;
}

//--------------QUEUE Opeartions----------------
void enQueue(char a[],int length)  // Inserting word in queue
{
    int i;
    if (rear==49) //Maximum Word Limit of Queue = 50
        {
        printf("\nQueue Overflow.No space to keep word");
        return;
        }
    else    
       {
        rear = rear+1;
        if(front==-1)   // If Queue is empty
            front=0;
        
        for(i=0;i<length; ++i)  // Copying String to the Queue[i]
            Queue[rear][i]=a[i];
        
        Queue[rear][i]='\0';    // Null Pointer at last
       }
    printf("Successfully inserted !!\n");
}

void display_Queue( )         // Display palindrome strings in Queue
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is empty !! No palindrome word is in the Queue \n");
        return;
    }
    printf("\nStrings in the Queue :- ");
    for(i=front; i<=rear; i++)
        printf(" %s ",Queue[i]);
}

