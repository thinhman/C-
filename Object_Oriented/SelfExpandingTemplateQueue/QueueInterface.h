#pragma once


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
  virtual void enqueue(ItemType item)=0;
  /**
	*Effect:         Removes front element from this queue and returns it.
  	*Precondition:   This queue is not empty.
  	*Post-conditions: Front element has been removed from this queue.
    *Return value = (the removed element)
    *@return the first item in the queue which is an <code>ItemType</code> object.
    */
  virtual ItemType dequeue( )= 0;
  /**
	*Effect:         Determines whether this queue is empty.
  	*Post-condition:  Return value = (this queue is empty)
  	*@return true is queue is empty else returns false.
  */
  virtual bool isEmpty( ) const = 0;
  /**
  *Default destructor.
  */
  virtual ~QueueInterface(){}
  /**
  *Default constructor.
  */
  QueueInterface(){}
};
#include "TemplateQueue.h"
