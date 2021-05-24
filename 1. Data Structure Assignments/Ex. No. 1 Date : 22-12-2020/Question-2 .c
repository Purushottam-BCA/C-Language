/* Q-2. Imagine numbered dinner plates are  organized one after the above the other like in a table as (4,2,7,4,3,1,8,9) and do the following actions:
        1. Identify which plate can be taken out first
        2. Identify which plate can be taken out last
        3. Include a new plate
        4. Remove a plate   */

#include <stdio.h>
#define N 10 // Maximum 10 plates can be kept
int dinner_plate[N]={4,2,7,4,3,1,8,9}; // initialisation of plate no.
int TOP = 7;

void push (int plate);
int pop();
void show_plate();

int main() 
{
    int i,opt,plate,del_plate;
    while (1)
    {
        printf("\n1. Find the plate that will be taken out first ");
        printf("\n2. Find the plate that will be taken out Last ");
        printf("\n3. Add anew plate ");
        printf("\n4. Remove a plate ");
        printf("\n5. Display all plates in order ");
        printf("\n6. Exit ");
        printf("\n\nEnter your choice : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("Plate at position %d : %d will be taken out first\n",TOP+1,dinner_plate[TOP]);
            break;
            case 2:
                printf("Plate at position 1 : %d will be taken out first\n",dinner_plate[0]);
            break;
            case 3:
                printf("Enter plate no : ");
                scanf("%d",&plate);
                push(plate);
            break;
            case 4:del_plate =pop();
                printf("Removed Plate No : %d\n",del_plate);
            break;
            case 5:
                show_plate();
            break;
            default:printf("Selectvalid option !");
        } // End of switch case
    }// End of while loop
} // End of main()

void push(int plate) // Insert new plate---------------* OUTPUT *----------------
{
    if(TOP==N-1)
        {
            printf("No place to putmore plates, Table is full");
            return;
        }
        TOP=TOP+1;
        dinner_plate[TOP]=plate;
}

int pop() // Remove a plate
{
    int temp;
    if(TOP==-1)
    {
        printf("No plates to remove (Zero Plates)");
        return 0;
    }
    temp =dinner_plate[TOP];
    TOP =TOP-1;
    return temp;
}

void show_plate()
{
    int i;
    if(TOP==-1)
    {
        printf("No plates to display (Table empty)");
        return;
    }
    for (i=TOP;i>=0;i--)
    printf(" %d \n",dinner_plate[i]);
}

