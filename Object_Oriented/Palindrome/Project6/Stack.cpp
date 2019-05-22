#include "Stack.h"

Stack::Stack()
{
	top_position = -1;
}

bool Stack::isEmpty() const
{
	return (top_position == -1);
}

bool Stack::isFull() const
{
	return (top_position == MAX1 - 1);
}

char Stack::top() const
{
	if (isEmpty())
	{
		cout << "\nStack is empty";
	}
	else
	{
		return stack[top_position];
	}
}

void Stack::pop()
{
	if (isEmpty())
	{
		cout << "\nThe stack is empty.\n";
		return;
	}
	else
	{
		top_position--;
	}
}

void Stack::push(char newChar)
{
	if (isFull())
	{
		cout << "\nThe stack is full. The item was not added.\n";
		return;
	}
	else
	{
		top_position++;
		stack[top_position] = newChar;
	}
}
