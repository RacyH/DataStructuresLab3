/*Racy Halterman
* Data Structures Spring 2021
* Due: February 17th
* Lab 3: Stack
* A general stack program.
* I should like to note that there is no mention in the requirements of what data type, or of having the datatype header/implementation files
*/

#include "Stack.h"
using namespace std;

void intro();
void menu(bool& ex);
void additem();
void deleteitem();
void viewitem();

Stack slist;

int main()
{
	bool sure = true;
		intro();
		menu(sure);//sure is passed through, i had it in an earlier implementation, but kept it so that if I wanted to mess around with it a bit more, I could.
	return 0;
}

/*
*Preconditions - Requires iostream and std libraries are loaded. Also must have Stack.h loaded. (iostream is in Stack.h)
*Postconditions - Ouputs a message so that the user knows what the program does.
*/
void intro()//Just displays the intro to the project for the user.
{
	char e;
	system("cls");
	cout << "This is a simple stack memory program.\n";
	cout << "You will be able add and remove items only from the top of the stack.\n";
	cout << "Items are limited to integers.\n";
	cout << "You will only be able to view the top item in the stack.\n";
	cout << "You will be able to add as many items as the system will allow, which may be different for each computer.\n";
	cout << "Press E, then enter, to exit this introduction and go into the menu.\n";
	cin >> e;
}

/*
*Preconditions - Requires Stack.h be loaded, along with all of it's components. Requires a bool to be passed through.
* Also requires that all of the functions work properly.
*Postconditions - Sends the user to complete function, until the user decides to exit.
*/
void menu(bool& ex)
{
	char menuitem;

	while (ex == true)
	{
		system("cls"); //clears the screen.

		cout << "Press the letter corresponding to the menu item that you would like to access.\n";
		cout << "Add item.\tA\n";
		cout << "Delete item.\tD\n";
		cout << "View item.\tV\n";
		cout << "Exit program.\tE\n";
		cin >> menuitem;
		switch (menuitem)//simple switch of the above menu items, and the users input.
		{
		case 'A': additem();
			break;
		case 'D': deleteitem();
			break;
		case 'V': viewitem();
			break;
		case 'E': ex = false;
			break; //These are in both capital and lowercase letters, just in case the user doesn't want to use capitals.
		case 'a': additem();
			break;
		case 'd': deleteitem();
			break;
		case 'v': viewitem();
			break;
		case 'e': ex = false;
			break;
		default: cout << "Invalid input. Please try again.\n";
			break;
		}
	}
}

/*
*Preconditions - Requires Stack::Push() is functioning, and that std and iostream are loaded. Stack.h is required.
*Postconditions - Adds the inputted item on top of the stack using the Push() function.
*/
void additem()//Do not try and push the number -404.
{
	int item;
	system("cls");
	cout << "What item do you want to add to the stack?\n";//simple function, asks for the item that they want to be added to the stack, then adds it
	cin >> item;
	slist.Push(item);
}

/*
*Preconditions - Requires iostream and std are loaded. Requires Stack.h.
*Postconditions - Removes the top item from the stack using the Pop() function.
*/
void deleteitem()
{
	char leave;
	cout << slist.Pop() << endl;
	cout << "Press any letter, followed by enter, to exit back to the menu.\n";
	cin >> leave;
}

/*
*Preconditions - Std and iostream are loaded. Requires Stack.h.
*Postconditions - Outputs the item that is on top of the list.
*/
void viewitem()
{
	char leave;
	system("cls");
	if (slist.Top() != -404)
	{
		cout << slist.Top() << endl;
		cout << "Press any letter, then enter, to exit back to the menu.\n";
		cin >> leave;
	}
	else
	{
		cout << "Error: " << slist.Top() << "- Not found.\n"; //Error: -404- not found.
		cout << "Press any letter, then enter, to exit back to the menu.\n";
		cin >> leave;
	}
}