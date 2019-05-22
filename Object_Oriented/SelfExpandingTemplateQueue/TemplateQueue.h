
#pragma once
#include "QueueInterface.h"

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
   ItemType  * items ; 
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
   ItemType dequeue( );
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

#include "TemplateQueue.cpp"