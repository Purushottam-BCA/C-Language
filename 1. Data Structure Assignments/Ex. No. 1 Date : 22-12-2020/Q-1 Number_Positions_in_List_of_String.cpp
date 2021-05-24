
/*
  Find a suitable data structures for the following scenarios and do the implementations:
  Q.1 Create a list L (123,234,345,456,567,678,789) and do the following operations using array concept.
        1. Insert a 010 at first position and show the order now
        2. Insert 020 at last position and show the order now
        3. Insert 030 at position 5 and show the order now
        4. Remove the item at 5 and 10
        5. Replace the item at 3 with 765 
*/

#include <iostream>
using namespace std;

string a[20] ={"123", "234", "345", "456", "567", "678", "789"};
int counter = 6;

void arrange (int pos, string value) {
    string temp = value;
    int change = 0;
    for (int i = 0; i < 20; i++)
        if (i == (pos) || change == 1)
    	{
            value = temp;
            temp = a[i];
	        a[i] = value;
	        change = 1;
        }
    counter++;
}

void display () 
{
    cout << "\nThe values are : \n";
    for (int i = 0; i < 20; i++)
    {
        if (a[i] != "")
	        cout << a[i] << endl;
    }
}

void removes (int pos) 
{
    for (int i = pos; i < 10; i++)
    {
        if (i != 9)
	        a[i] = a[i + 1];
        else
            a[i] = " ";
    }
    cout << "\nDeleted Value : " << a[pos] << endl;
}

void update (int loc, string value) 
{
    a[loc] = value;
} 
 
int main () 
{
    int opt, index;
    string temp;
    while (1)
    {
    cout <<"\nChoose an option : \n1.Insert a value\n2.Delete a value\n3.display all value \n4.Update \n5.Exit ";
    cout << "\nEnter the choice : ";
    cin >> opt;
    switch (opt)
	{
	    case 1:
	        cout << "\nEnter the value : ";
	        cin >> temp;
            cout << "\nEnter the position : ";
            cin >> index;
            arrange (index - 1, temp);
            display ();
        break;
        case 2:
            cout << "\nEnter the position : ";
            cin >> index;
            removes (index - 1);
            display ();
        break;
        case 3: 
            display ();
        break;
        case 4:
            cout << "\nEnter the position : ";
            cin >> index;   
            cout << "\nEnter the value : ";
            cin >> temp;
            update (index - 1, temp);
            display ();
        break;
        case 5:
            exit (0);
        break;
        default:
            cout << "Enter Correct option !";
        }	// End of switch.
    }	// End of while.
  return 0;
}	//End of main 
