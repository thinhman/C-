#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

const size_t MAX1 = 100;

class Stack
{
private:
	int top_position;
	char stack[MAX1];
public:
	void push(char item);
	void pop();
	char top() const;
	bool isEmpty() const;
	bool isFull() const;
	Stack();
};
#endif