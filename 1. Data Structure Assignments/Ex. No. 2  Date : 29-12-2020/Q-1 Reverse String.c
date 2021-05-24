/* 
   Question :- Find a suitable data structure for string reversal and implement the same.

   Approach :- For string reversal , Stack is the suitable Data structure. Stackfollows LIFO method.
               1. So first we will insert a string in STR. 
               2. Then we push each character of the string one by one into the stack.So 1st character of 
                  string will be inserted first & the last character of string will be denoted by stack[TOP].
               3. Since stack follows LIFO rule so, the last character of string will be deleted first 
                  while performing POP( ) operation.
               4. Then We will Pop all characters, one by one and put into the another string called ReverseSTR. 
                  So the value kept in ReverseSTR isthe reverse of STR.    
*/

#include <stdio.h>
#include <string.h>

#define MAX 50	// maximum no. of characters //

int TOP =-1;
char item;

char stack[MAX];

void push(char item);
char pop(void);

int isEmpty(void);
int isFull(void);
 
int main()
{
    char opt,ReverseSTR[MAX];
    int i;

    printf("Enter a word : ");
    scanf("%[^\n]s",str);        // "%[^\n]s" is used to enter string with space  
    
    for(i=0; i<strlen(str); i++)
        push(str[i]);
        
    for(i=0; i<strlen(str); i++)
        ReverseSTR[i]=pop();

    printf("Reverse of %s is : %s\n",str,ReverseSTR);
  return 0;
}
 
void push(char item)
{
    if(isFull())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    TOP = TOP + 1;
    stack[TOP] =item;
}
 
char pop()
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

