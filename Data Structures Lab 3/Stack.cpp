/*Racy Halterman
* Data Structures Spring 2021
* Due: February 17th
* Lab 3: Stack
* A general stack program.
*/

#include "Stack.h"

Stack::Stack()
{
	topitem = nullptr; //Sets the topitem to be null
}

Stack::~Stack()
{
	while (!(IsEmpty())) //Goes through the list and destroys the items in it.
	{
		Pop();
	}
}

bool Stack::IsEmpty()
{
	return (topitem == NULL);
}

bool Stack::IsFull()
{
	try
	{
		node* attempt = new node;
		delete attempt;
		return false;//If it can do this, then it returns false.
	}
	catch (std::bad_alloc& ba) //Pulled this off D. Busch's example. It works, so why not?
	{
		return true;
	}
}

void Stack::Push(int value)
{
	if (!(IsFull()))
	{
		node* temp = new node;
		temp->data = value;
		temp->next = topitem; //Sets the new node next to the most previous top item.
		topitem = temp; //Sets the top item as the temp node.
	}
}

int Stack::Pop()
{
	node* temp; //creat temp node.
	int p;
	temp = topitem; //set temp node to the top.
	p = temp->data; //sets p as the temp's data.
	topitem = topitem->next; //moves topitem to the next item.
	free(temp); //I saw this somewhere, and thought it was cool, and so I tried it. Basically, it just deallocates the memory.
	return p; //returns the value that was deleted.
}

int Stack::Top()
{
	if (!(IsEmpty()))
	{
		return topitem->data;
	}
	else
		return -404;
}