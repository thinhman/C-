#pragma once
#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#include "ItemType.h"

class StackInterface
{
public:

	virtual void push(ItemType item) = 0;

	virtual void pop() = 0;

	virtual ItemType top() const = 0;
	
	virtual bool isEmpty() const = 0;
	
	virtual bool isFull() const = 0;
	
	StackInterface() {}
	
	virtual ~StackInterface() {}
};

#endif