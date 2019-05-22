

#include <iostream>
#include <cstdlib>
using namespace std;

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
	cerr<<"Memory assignment error.\n";
	throw "Memory assignment error.";
}
//---------------------------------------------------------
template<typename ItemType>
void Queue<ItemType>::destroy()
{
	delete [] items;
}
//////////////////////////////////////////
/////////////////////////////////////////////////////
template<typename ItemType>
void Queue<ItemType>::copy(const Queue<ItemType>& Other)
{
	if(!(items = new ItemType[Other.numItems]))
	{
		memoryError();
	}
	
	for(int index=0; index<other.numItems; index++)
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
	if(this == &Other)
	{
		cerr<<"Self copying is illegal and un-necessary.\n";
		throw "Exiting due to self copy error.";
	}
	copy(Other);
}
//////////////////////////////////////////////
template<typename ItemType>
const Queue<ItemType>& Queue<ItemType>::operator = (const Queue<ItemType>& Other)
{
	if(this != &Other)
	{
		destroy();
		copy(Other);
	}
	
	return *this;
}
////////////////////////////////////////////
template<typename ItemType>
Queue<typename ItemType>::Queue() : items ( new ItemType[MAX]),
numItems(0), front(0), rear(-1), capacity(MAX)
 {
  }
//--------------------------------------------------------------------
template<typename ItemType>
void Queue<typename ItemType>::enqueue(ItemType item)
  {
	  if(capacity > numItems)
	  {
		 rear = (rear + 1) % capacity;
         items[rear] = item;
         numItems = numItems + 1;
	  }
	  else
	  {
		int len = capacity+GROW;
		ItemType * Temp;

		if(!(Temp = new ItemType[len]))
		{
			memoryError();
		}

		for(int index = 0; index<numItems; index++)
		{
			Temp[index] = items[index];
		}

		destroy();
		items = Temp;
		Temp = nullptr;
		capacity = len;
		front = 0;
		rear = (rear + 1) % capacity;
        items[rear] = item;
        numItems = numItems + 1;
	  }
  }
//-------------------------------------------------
template<typename ItemType>
ItemType Queue<typename ItemType>::dequeue( ) 
{
       if(isEmpty ( ) )
           {
		cerr<<"\nThe queue is empty.\n";
                  throw "The queue is empty";
           }
     else
     {
          ItemType toReturn = items[front];
		  front = (front + 1) % capacity;
          numItems --;
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
