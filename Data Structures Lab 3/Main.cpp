/*Racy Halterman
* Data Structures Spring 2021
* Due: February 17th
* Lab 3: Stack
*
*/

#include "Stack.h"
using namespace std;

void intro();
void menu();
void additem();
void deleteitem();
void viewitem();

Stack slist;

void main()
{
	char sure = 'f';
	while (sure != 'E' && sure != 'e')
	{
		intro();
		menu();
		cout << "Are you sure that you would like to exit? Press E to exit the program.\n";
	}
}

void intro()
{
	char e;
	cout << "This is a simple stack memory program.\n";
	cout << "You will be able add and remove items only from the top of the stack.\n";
	cout << "You will only be able to view the top item in the stack.\n";
	cout << "You will be able to add as many items as the system will allow, which may be different for each computer.\n";
	cout << "Press E, then enter, to exit this introduction and go into the menu.\n";
	cin >> e;
}

void menu()
{
	system("cls");
	char menuitem;
	bool choice = false;
	bool exit = false;
	cout << "Press the letter corresponding to the menu item that you would like to access.\n";
	cout << "Add item.\tA\n";
	cout << "Delete item.\tD\n";
	cout << "View item.\tV\n";
	cout << "Exit program.\tE\n";
	while (choice == false && exit == false)
	{
		cin >> menuitem;
		switch (menuitem)
		{
		case 'A': additem();
			choice = true;
			break;
		case 'D': deleteitem();
			choice = true;
			break;
		case 'V': viewitem();
			choice = true;
			break;
		case 'E': choice = true;
			break;
		case 'a': additem();
			choice = true;
			break;
		case 'd': deleteitem();
			choice = true;
			break;
		case 'v': viewitem();
			choice = true;
			break;
		case 'e': choice = true;
			exit = true;
			break;
		default: cout << "Invalid input. Please try again.\n";
			break;
		}
	}
}

void additem()
{
	int item;
	system("cls");
	cout << "What item do you want to add to the stack?\n";
	cin >> item;
	slist.Push(item);
}

void deleteitem()
{
	system("cls");
	slist.Pop();
}

void viewitem()
{
	system("cls");
	cout << slist.Top();
}