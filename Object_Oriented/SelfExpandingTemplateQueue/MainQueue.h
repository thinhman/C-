#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

/**
*Class <code>QueueInterface</code> is an abstract class conatining ALL
*pure virtual functions and destructor which defines the pure design for
*the base class or supertype for the concrete queue classes to be derived from.
*/
template<typename ItemType>
class QueueInterface
{
public:
	/**
	*Effect:         Adds item to the rear of this queue.
	*Precondition:   This queue is not full.
	*Post-condition:  item is at the rear of this queue.
	*@param item is the <code>ItemType</code> object added to the queue.
	*/
	virtual void enqueue(ItemType item) = 0;
	/**
	*Effect:         Removes front element from this queue and returns it.
	*Precondition:   This queue is not empty.
	*Post-conditions: Front element has been removed from this queue.
	*Return value = (the removed element)
	*@return the first item in the queue which is an <code>ItemType</code> object.
	*/
	virtual ItemType dequeue() = 0;
	/**
	*Effect:         Determines whether this queue is empty.
	*Post-condition:  Return value = (this queue is empty)
	*@return true is queue is empty else returns false.
	*/
	virtual bool isEmpty() const = 0;
	/**
	*Default destructor.
	*/
	virtual ~QueueInterface(){}
	/**
	*Default constructor.
	*/
	QueueInterface(){}
};

template<typename ItemType>
class Queue : public QueueInterface<ItemType>
{
private:
	/**
	*The maximum default size of the queue, when created first time.
	*/
	static const int MAX = 1;
	/**
	*Default size by which the queue will grow, when it is filled and more elements are
	*added.
	*/
	static const int GROW = 1;
	/**
	*Current physical capacity of the queue
	*/
	int capacity;
	/**
	*Pointer to an array of ItemType that holds queue elements
	*and has an initial capacity equal to MAX.
	*/
	ItemType  * items;
	/**
	*Number of items in the queue (less than or equal to MAX )
	*/
	int numItems;
	/**
	*index of front pointer of queue.
	*/
	int front;
	/**
	*index of rear pointer of queue.
	*/
	int rear;
public:
	/**
	* Default constructor sets the numItems = 0, front = 0,
	*rear = -1, capacity to MAX, and allocates the memory for array pointer
	member items.
	*/
	Queue();
	/**
	*Enqueues the item and adds to the rear of the queue. If queue is filled then
	*increases its capacity by static member GROW.
	*/
	void enqueue(ItemType item);
	/**
	*Removes the item from the front of the queue and returns it. If queue is empty tghen throws
	*an exception. Syntax of throwing exception is simply:
	*throw "Queue is Empty";
	*/
	ItemType dequeue();
	/**
	*Returns true if queue is empty, otherwise returns false.
	*/
	bool isEmpty() const;
	/**
	*Default destructor deallocates the dynamically allocated memory in
	*the constructor.
	*/
	virtual ~Queue();
	/**
	*Copy constructor.
	*/
	Queue(const Queue& Other);
	/**
	*Assignment operator.
	*/
	const Queue & operator = (const Queue& Other);
	/**
	*   Returns the current capacity of the Queue.
	*/
	int getCapacity()const;
protected:
	/**
	*Protected member function destroy is called when one needs to explicitly
	*destroy a Queue.
	*/
	void destroy();
	/**
	*Called when the operating system fails to allocated memory with invocation of new.
	*/
	void memoryError();
	/**
	*Protected member function copy is called internally when
	*the Other Queue needs to be copied into the current Queue.
	*/
	void copy(const Queue& Other);
};


//-----------------------------------------------------------
template<typename ItemType>
int Queue<ItemType>::getCapacity()const
{
	return capacity;
}

//----------------------------------------------------------
template<typename ItemType>
void  Queue<ItemType>::memoryError()
{
	cerr << "Memory assignment error.\n";
	throw "Memory assignment error.";
}
//---------------------------------------------------------
template<typename ItemType>
void Queue<ItemType>::destroy()
{
	delete[] items;
}
//////////////////////////////////////////
/////////////////////////////////////////////////////
template<typename ItemType>
void Queue<ItemType>::copy(const Queue<ItemType>& Other)
{
	if (!(items = new ItemType[Other.numItems]))
	{
		memoryError();
	}

	for (int index = 0; index<other.numItems; index++)
	{
		items[index] = Other.items[index];
	}

	numItems = Other.numItems;
	capacity = Other.capacity;
	front = Other.front;
	rear = Other.rear;
}

/////////////////////////////////////////
template<typename ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& Other)
{
	if (this == &Other)
	{
		cerr << "Self copying is illegal and un-necessary.\n";
		throw "Exiting due to self copy error.";
	}
	copy(Other);
}
//////////////////////////////////////////////
template<typename ItemType>
const Queue<ItemType>& Queue<ItemType>::operator = (const Queue<ItemType>& Other)
{
	if (this == &Other)
	{
		return *this;
	}
	destroy();
	copy(Other);
	return *this;
}
////////////////////////////////////////////
template<typename ItemType>
Queue<typename ItemType>::Queue()
{
	items = new ItemType[MAX];
	numItems = 0;
	front = 0;
	rear = -1;
	capacity = MAX;
}
//--------------------------------------------------------------------
template<typename ItemType>
void Queue<typename ItemType>::enqueue(ItemType item)
{
	if (capacity > numItems)
	{
		rear = (rear + 1) % capacity;
		items[rear] = item;
		numItems = numItems + 1;
	}
	else
	{
		int len = capacity + GROW;
		ItemType * Temp;

		if (!(Temp = new ItemType[len]))
		{
			memoryError();
		}

		for (int index = 0; index<numItems; index++)
		{
			Temp[index] = items[index];
		}

		destroy();
		items = Temp;
		Temp = NULL;
		capacity = len;
		front = 0;
		rear = (rear + 1) % capacity;
		items[rear] = item;
		numItems = numItems + 1;
	}
}
//-------------------------------------------------
template<typename ItemType>
ItemType Queue<typename ItemType>::dequeue()
{
	if (isEmpty())
	{
		cerr << "\nThe queue is empty.\n";
		throw "The queue is empty";
	}
	else
	{
		ItemType toReturn = items[front];
		front = (front + 1) % capacity;
		numItems--;
		return toReturn;
	}
}

//---------------------------------------------
template<typename ItemType>
bool Queue<typename ItemType>::isEmpty() const

{
	return (numItems == 0);
}
//----------------------------------------
//--------------------------------------------
template<typename ItemType>
Queue<typename ItemType>::~Queue()
{
	destroy();
}
//--------------------------------------------------------------------

