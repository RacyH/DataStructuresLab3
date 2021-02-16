/*Racy Halterman
* Data Structures Spring 2021
* Due: February 17th
* Lab 3: Stack
*
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <string>

class Stack
{
private:
	struct node
	{
		int data;
		node* next;
	};

	node *topitem;

public:
	Stack();
	~Stack();
	bool IsEmpty();
	bool IsFull();
	int Pop();
	void Push(int value);
	int Top() { return topitem->data; };
};


#endif  //!STACK_H