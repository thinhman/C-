#include "StringQueue.h"
StringQueue::StringQueue() : frontPointer(0), numItems(0), rear(-1)
{
	/*frontPointer = 0;
	numItems = 0;
	rear = -1;*/
}
bool StringQueue::isEmpty() const
{
	return (numItems == 0);
}
void StringQueue::enqueue(char val)
{
	
	if (numItems == MAX)
	{
		cerr << "The queue is full. The item is not added.\n";
		return;
	}
	else
	{
		rear = (rear + 1) % MAX;
		que[rear] = val;
		numItems++;
	}
}
int StringQueue::dequeue()
{
	if (isEmpty())
	{
		cerr << "\nThe queue is empty.\n";
		exit(0);
	}
	else
	{
		char toReturn;
		toReturn = que[frontPointer];
		frontPointer = (frontPointer + 1) % MAX;
		numItems--;
		return toReturn;
	}
}
StringQueue::~StringQueue()
{

}