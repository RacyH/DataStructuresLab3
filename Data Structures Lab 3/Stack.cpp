/*Racy Halterman
* Data Structures Spring 2021
* Due: February 17th
* Lab 3: Stack
*
*/

#include "Stack.h"

Stack::Stack()
{
	topitem = nullptr;
}

Stack::~Stack()
{
	while (!(IsEmpty()))
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
		return false;
	}
	catch (std::bad_alloc& ba)
	{
		return true;
	}
}

void Stack::Push(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = topitem; //Sets the new node next to the most previous top item.
	topitem = temp; //Sets the new node as the top item.
}

int Stack::Pop()
{
	node* temp;
	int p;
	temp = topitem;
	p = temp->data;
	topitem = topitem->next;
	free(temp);
	return p;
}