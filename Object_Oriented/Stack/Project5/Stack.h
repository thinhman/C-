#pragma once
#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"

using namespace std;

const size_t MAX = 30;

class Stack : public StackInterface
{
private:
	int top_position;
	ItemType items[MAX];
public:
	void push(ItemType item);
	void pop();
	ItemType top() const;
	bool isEmpty() const;
	bool isFull() const;
	Stack();
	~Stack();
};

#endif