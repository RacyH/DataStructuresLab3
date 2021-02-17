/*Racy Halterman
* Data Structures Spring 2021
* Due: February 17th
* Lab 3: Stack
* A general stack program.
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
private:
	struct node
	{
		int data; //Holds the data of the node.
		node* next; //Holds the value of the next node.
	};

	node *topitem;

public:

/*
*Preconditions - Requires the node struct is correct. Iostream as well.
*Postconditions - Constructs the stack.
*/
	Stack();

/*
*Preconditions - Requires Pop and IsEmpty are loaded. Also iostream.
*Postconditions - Destroys the stack.
*/
	~Stack();

/*
*Preconditions - Requires iostream and the node struct, and the node topitem.
*Postconditions - Returns true if the topitem is null, false if it doesn't.
*/
	bool IsEmpty();

/*
*Preconditions - Requires the node struct and iostream.
*Postconditions - Returns true if the stack has hit max capacity in the computers memory. False if otherwise.
*/
	bool IsFull();

/*
*Preconditions - Requires node struct, topitem, and iostream.
*Postconditions - Returns the new top value of the stack after destroying the top item.
*/
	int Pop();

/*
*Preconditions - Requires IsFull, iostream, node, and topitem.
*Postconditions - Places the number inputted on top of the stack.
*/
	void Push(int value);

/*
*Preconditions - Iostream, node struct, and topitem.
*Postconditions - Returns the data within the topitem of the stack.
*/
	int Top();
};


#endif  //!STACK_H