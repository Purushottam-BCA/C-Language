/* Q-3. Imagine a tollgate with only one counter, The following cars are waiting in the queue: TN601234, TN010978, TN453452, TN606116
        1. What is the position of the car TN010978?
        2. What is the position of the newly arrived car TN596754?
        3. Identify the car which gets served first
        4. Identify the car which gets served last
        5. What will be the next car that get served after TN453452?
*/

#include <iostream>
using namespace std;
string Queue[10]={"TN601234","TN010978","TN453452","TN606116"};
int front=0, rear=3;

void push(string s)  // Inserting New car in queue
{
    if (rear==9)
        {
        cout<<"\nQueue Overflow.No space to keep car";
        return;
        }
    else
    {
        rear=rear+1;
        Queue[rear]=s;
        if(front==-1)
            front=0;
    }
    cout<<"\nCar No : "<<s<<" waiting at "<<rear<<" position.\n";
}
 
/* Deletion is not required in this problem, so it is optional. 
void pop() //Removing cars from queue
{
    if(front==-1 )
    {
        cout<<"Nothing to delete";
        return;
    }
    string temp=Queue[front];
    cout<<"\n Deleted Value : "<<temp;
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    front = front+1;
}  */

void nextcar(string temp)    // To find the next car served after a car
{
 for(int i=front;i<=rear;i++)
    If (Queue[i]==temp)
        cout<< "\nCar served after "<<temp<<" : "<< Queue[i+1]<<endl;
}

void display( )         // Display cars in waiting Queue
{
    int j=1;
    if(front==-1)
    {
        cout<<"Queue is empty";
        return;
    }
    cout<<"\nCars No  -  Waiting No.\n";
    for(int i=front;i<=rear;i++,j++)
    cout<<Queue[i]<<"   -   "<<j<<endl;
}

void position(string value)   // Finding Position of Car
{
   int flag=0;
   for(int i=front;i<=rear;i++)
    if(value==Queue[i])
    {
        cout<<"\nPosition of Car "<<value<<" : "<<i+1;
        flag=1;
    }
    if (flag==0)
     cout<<"\nCar No. not found";
}

int main( )
{
    int opt;
    string CarNo;
    while(1)
    {
    cout<<"\n\n1.New Car arrival Entry \n2.Find Position of Car \n3.Find Position of Newly arrived car\n4.Car which will be served First";
    cout<<"\n5.Car which will be served at Last\n6.Car served after any Particullar Car \n7.Display Cars in waiting queue \n8.Exit";
    cout<<"\nChoose an option : ";
    cin>>opt;
    switch(opt)
    {
        case 1: 
            cout<<"\nEnter Car No : ";
            cin>>CarNo;
            push(CarNo);
            display();
            break;
        case 2: 
            cout<<"Enter Car No to find its Position : \n";
            cin>>CarNo;
            position(CarNo);
            break;
        case 3: 
            cout<<"\nEnter New Car No : ";
            cin>>CarNo;
            push(CarNo);
            position(CarNo);
            break;
        case 4: 
            cout<<"\n Car No : "<<Queue[front]<<" will be  served First.";
            break;
        case 5: 
            cout<<"\n Car No : "<<Queue[rear]<<" will be  served at Last.";
            break;
        case 6: 
            cout<<"\n Enter Carno : ";
            cin>>CarNo;
            nextcar(CarNo);
            break;
        case 7:
            display();
            break;
        case 8:
            return 0;
            break;
        default:
            cout<<"choose valid option";
      } //End of switch
    } //End of while loop
   return 0;
 } //End of main function

