#pragma once
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
const int MAX = 100;
class StringQueue 
{
private:	
	int numItems;
	int frontPointer;
	int rear;
	char que[MAX];
public:
	/**
	* Default constructor sets the numItems = 0, front = 0,
	*rear = -1.
	*/
	StringQueue();
	void enqueue(char val);
	int dequeue();
	bool isEmpty() const;
	~StringQueue();
};
#endif