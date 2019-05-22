#pragma once
#ifndef LINKED_LIST_INTERFACE_H
#define LINKED_LIST_INTERFACE_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <typeinfo>
using namespace std;

//#define DEBUG

/**
*Counter to keep track of memory allocation/de-allocation
*/
static int counter = 0;
/**
*Node is a templated class, which creates a node to be added
*to a linked list of either basic types or user defined types.
*/
template<typename Type>
class Node
{
public:
	/**
	*data is the template parameter, which is either basic type
	(or user defined type.
	*/
	Type data;
	/**
	*Next is the pointer to Node type object.
	*/
	Node * Next;
	/**
	*Default/explicit constructor for class Node
	*/
	Node(Type init_data=Type(), Node * Next1 = nullptr)
	{
		data = init_data;
		Next = Next1;
	}
	/**
	*Overloaded insertion operator << for class Node.
	*/
	friend ostream& operator << (ostream& out, const Node<Type>& IL)
	{
		out<<IL.data<< "    ";
		return out;
	}
	/**
	*Overloaded extraction operator >> for class Node.
	*/
	friend istream& operator >>(istream& in, Node& IL)
	{
		in>>IL.data;
		return in;
	}
	/**
	*Virtual destructor. No code needed.
	*/
	virtual ~Node() { }
	/**
	*Returns the type of the data field of Node as a string.
	*/
	string getType()
	{
		return typeid(data).name();
	}
};
//////////////////////////////////////////////////////////
/**
*Abastract class, LinkedListInterface class provides the essential methods for a 
*linked list class.
*/
template<typename Type>
class LinkedListInterface
{
public:
	/**
	*Adds the item to the front of the List.
	*/
	virtual	void addFront(Type Item)=0;
	/**
	*Adds the Item to the rear of the List.
	*/
	virtual	void addRear(Type Item)=0;
	/**
	*Removes the front item from the list.
	*/
	virtual	void removeFront()=0;
	/**
	*Removes the Rear Item from the List.
	*/
	virtual	void removeRear()=0;
	/**
	*Returns the front item in the list.
	*/
	virtual	const Type getFront() const =0;
	/**
	*returns the rear item from the list.
	*/
	virtual	const Type getRear()const =0;
	/**
	*Returns true if Item is in the list, else returns false.
	*/
	virtual	bool contains(const Type& Item)const=0;
	/**
	*Returns the size of the list.
	*/
	virtual	int size() const=0;
	/**
	*
	*/
	virtual	bool isEmpty() const =0;
	/**
	*Default constructor
	*/
	LinkedListInterface() {}
	/**
	*Default virtual destructor
	*/
	virtual ~LinkedListInterface() { }
};
////////////////////////////////////////
/**
*Concrete class SinglyLinkedList derives from the LinkedListInterface
* as a public derivation and provides the implementation of all
*of the super class pure virtual functions.
*/
template<typename Type>
class SinglyLinkedList:public LinkedListInterface<Type>
{
private:
	/**
	*Poniter to the head or front node of linked list.
	*/
	Node<Type> * Head;
	/**
	*Pointer to the rear node or last node in the linked list
	*/
	Node<Type>* Rear;
	/**
	*Pointer which, can iterate through the linked list as needed.
	*/
	Node<Type>* Iterator;
	/**
	*Number of elements in the linked list.
	*/
	int num_elements;
public:
	/**
	*Default constructor for the linked list.
	*/
	SinglyLinkedList(); //done
	/**
	*Copy constructor for the linked list.
	*/
	SinglyLinkedList(const SinglyLinkedList& Other);//done
	/**
	*Overloaded assignment operator for linked list.
	*/
	const SinglyLinkedList& operator = (const SinglyLinkedList& Other);//done
	/**
	*Method deletes all dynamically allocated memory in the list.
	*/
	void destroy();//done
	/*
	*Virtual destructor for the linked List.
	*/
	virtual ~SinglyLinkedList();//done

	void addFront(Type Item);//done
	void addRear(Type Item);//done
	void removeFront();//done
	void removeRear();//done
	const Type getFront()const;//done
	const Type getRear()const;//done
	bool contains(const Type& Item)const;//done
	int size()const;//done
	bool isEmpty()const;//done
	/**
	*Prints the list from front to back.
	*/
	void printForward(ostream& out)const;//done
	/**
	*Prints the list from back to front.
	*/
	void printBackward(ostream& out)const;//done
	/**
	*Makes the list either from user input or by reading data from a file.
	*/
	void getList(istream& in, int flag);//done
	/**
	*Inserts the obj, after the target in the list.
	*/
	void addAfter(Type obj, Type target);//done
	/**
	*Inserts the obj before the first occurence of target as scanning the
	*list forward from the Head node.
	*/
	void addBefore(Type obj, Type target);//done
	/**
	*Removes the Node after the Node containing target, when the list is
	*scanned forward from the Head node. Displays a message and exits the
	*method by doing a void return if target is not in the list or
	*target is the last Node in the list.
	*/
	void removeAfter(Type target);//Lab6 part 2
	/**
	*Removes the Node before the Node containing target, when the list is
	*scanned forward from the Head node. Displays a message and exits the
	*method by doing a void return if target is not in the list or
	*target is the first Node in the list.
	*/
	void removeBefore(Type target);//Lab6 part 2
	/**
	*Returns the data value in the Node after the Node which contains
	*the data value target. Exits the program (using exit(1)) if the 
	*target is not in the list or if target is last element in the list.
	*Search is done scanning the list forward from front Node.
	*/
	const Type elementAfter(Type target) const;//done
	/**
	*Returns the data value in the Node before the Node which contains
	*the data value target. Exits the program (using exit(1)) if the 
	*target is not in the list or if target is first element in the list.
	*Search is done scanning the list forward from front Node.
	*/
	const Type elementBefore(Type target) const;//done
	/**
	*Prints linked list from front to rear using the a recursive print function.
	*/
	void printForwardRecursively(ostream& out)const;
	/**
	*Prints the list in forward order only.
	*/
	friend ostream& operator <<(ostream& out, const SinglyLinkedList<Type>& SL)
	{
		SL.printForward(out);
		return out;
	}
	Node<Type>* retrieveHead() const
	{
		return Head;
	}
protected:
	/**
	*Copies the linked list Other to the caller object.
	*/
	void copy(const SinglyLinkedList& Other);//Lab6 part2
	/**
	*Reads the data from file only to build the linked list and adds the 
	* data to linked list using addRear method.
	*/
	friend istream& operator >>(istream& in,  SinglyLinkedList& SL);//done
	/**
	*Gets the pointer to the first node containing the data field as
	*value, while scanning the list forward from Head pointer.
	*/
	const Node<Type> * getNode(Type value) const;//done
	/**
	*Returns a pointer to the Node before Some_Node if found or returns nullptr
	*if not found.
	*/
	const Node<Type> * nodeBefore(const Node<Type> * Some_Node) const;//done
	/**
	*Merges two or more lists together and returns the merged list.
	*/
	friend const SinglyLinkedList operator + ( const SinglyLinkedList & List1,
		const SinglyLinkedList& List2)
	{
		SinglyLinkedList<Type> temp;// = List1;
		/**
		*Fill data from List1 and List2 into temp. Use addFront method to add to
		*temp.
		*/

#ifdef DEBUG
		cout << temp;
#endif
		temp.addRear(List1.Head->data);
		Node<Type> *tempNode = List1.Head;
		while(tempNode->Next != nullptr)
		{
			temp.addRear(tempNode->Next->data);
			tempNode = tempNode->Next;
#ifdef DEBUG
			cout << temp;
#endif
		}

		temp.addRear((List2.Head)->data);
		tempNode = List2.Head;
		while(tempNode->Next != nullptr)
		{
			temp.addRear(tempNode->Next->data);
			tempNode = tempNode->Next;
#ifdef DEBUG
			cout << temp;
#endif
		}
		return temp;
	}//Lab6 part2

	friend bool operator== (const SinglyLinkedList<Type> &List1,
		const SinglyLinkedList<Type> &List2)
	{
		if(List1.num_elements != List2.num_elements)
			return false;

		Node<Type> *tempNode1 = List1.Head;
		Node<Type> *tempNode2 = List2.Head;

		while(tempNode1 != nullptr && tempNode2 != nullptr)
		{
			if(tempNode1->data != tempNode2->data)
				return false;
			tempNode1 = tempNode1->Next;
			tempNode2 = tempNode2->Next;
		}

		return true;
	}

	friend bool operator!= (const SinglyLinkedList<Type> &List1,
		const SinglyLinkedList<Type> &List2)
	{
		return !(List1 == List2);
	}
};
///////////////////////////////////////////////////////////////////////
//Compelete below as part of Lab6 Part 2
////////////////////////////////////////////////////////////////////////
template<typename Type>
void SinglyLinkedList<Type>::removeAfter(Type target)
{
	//Complete as part of Lab 6 Part B
	Node<Type> *temp = Head;
	while(temp != nullptr)
	{
		if(temp->data == target)
			break;
		temp = temp->Next;
	}
	if(temp == nullptr)
	{
		cout << "The target was not found in list\n";
		return;
	}
	else if(temp->Next == nullptr)
	{
		cout << "The target is the last element of the list\n";
		return;
	}
	else
	{
		Node<Type> *After = temp->Next;
		temp->Next = temp->Next->Next;
		delete After;
	}
}
//////////////////////////////////////////////////////////////////
template<typename Type>
void SinglyLinkedList<Type>::removeBefore(Type target)
{
	//Complete as part of Lab 6 Part B
	Node<Type> *temp = Head;
	Node<Type> *beforeTemp = nullptr;
	Node<Type> *beforeBeforeTemp = nullptr;
	while(temp != nullptr)
	{
		if(temp->data == target)
			break;
		beforeBeforeTemp = beforeTemp;
		beforeTemp = temp;
		temp = temp->Next;
	}
	if(temp == nullptr)
	{
		cout << "The target was not found in list\n";
		return;
	}
	else if(beforeTemp == nullptr)
	{
		cout << "The target is the first element of the list\n";
		return;
	}
	else if(beforeBeforeTemp == nullptr)
	{
		Head = temp;
		delete beforeTemp;
	}
	else
	{
		Node<Type> *Delete = beforeTemp;
		beforeBeforeTemp->Next = beforeBeforeTemp->Next->Next;
		delete Delete;
	}


}
//////////////////////////////////////////////////////////////////
template<typename Type>
void SinglyLinkedList<Type>::copy(const SinglyLinkedList<Type>& Other)
{
	this->num_elements = 0;
	//Complete as part of Lab 6 Part B
	Node<Type> *tempNode = Other.Head;
	while(tempNode != nullptr)
	{
		this->addRear(tempNode->data);
		tempNode = tempNode->Next;
	}	
}
//////////////////////////////////////////////////////////////////
//Lab6 part2 Assignment finished.
//////////////////////////////////////////////////////////////////
template<typename Type>
SinglyLinkedList<Type>::SinglyLinkedList()
{
	Head = nullptr;
	Rear = nullptr;
	Iterator = nullptr;
	num_elements = 0;
}

template<typename Type>
SinglyLinkedList<Type>::SinglyLinkedList(const SinglyLinkedList<Type>& Other)
{
	if(this == &Other)
	{
		cerr<<"Self copying is illegal and unnecessary. Exiting the program.\n";
		exit(1);
	}
	copy(Other);
}

template<typename Type>
const SinglyLinkedList<Type>& SinglyLinkedList<Type>::
operator = (const SinglyLinkedList<Type> & Other)
{
	if(this == &Other)
		return *this;
	destroy();
	copy(Other);
	return *this;
}

template<typename Type>
ostream& operator <<(ostream& out, const SinglyLinkedList<Type>& SL)
{
	SL.printForward(out);
	return out;
}

template<typename Type>
void SinglyLinkedList<Type>::addFront(Type Item)
{
	Node<Type> * New_Node = new Node<Type>(Item,Head);
	counter++;
	Head = New_Node;
	if(num_elements == 0)
		Rear = Head;
	num_elements++;
}

template<typename Type>
void SinglyLinkedList<Type>::addRear(Type Item)
{
	Node<Type> * New_Node = new Node<Type>(Item,nullptr);
	counter++;

	if(num_elements == 0)
	{
		Head = New_Node;
		Rear = New_Node;
	}
	else
	{
		Rear->Next = New_Node;
		Rear = New_Node;
	}
	num_elements++;
}

template<typename Type>
void SinglyLinkedList<Type>::printForward(ostream& out)const
{
	Node<Type> * Iterator1 = Head;

	while(Iterator1 !=nullptr)
	{
		out<<Iterator1->data<<"  ";
		Iterator1 = Iterator1->Next;
	}
	cout<<endl;
}

template<typename Type>
bool SinglyLinkedList<Type>::isEmpty() const
{
	return num_elements == 0 ;
}

template<typename Type>
int SinglyLinkedList<Type>::size() const
{
	return num_elements;
}

template<typename Type>
void SinglyLinkedList<Type>::removeFront()
{
	if(isEmpty())
	{
		cerr<<"The linked list is empty. Program will end.\n";
		exit(1);
	}

	Iterator = Head;
	Head = Head->Next;
	delete Iterator;
	counter--;
	num_elements--;

	if(num_elements == 0)
		Rear = nullptr;
}

template<typename Type>
void SinglyLinkedList<Type>::removeRear()
{
	if(isEmpty())
	{
		cerr<<"The linked list is empty. Program will end.\n";
		exit(1);
	}
	else if(num_elements == 1)
	{
		delete Head;
		counter--;
		Head = nullptr;
		Rear = nullptr;
	}
	else
	{
		Iterator = Head;

		while(Iterator->Next != Rear)
			Iterator = Iterator->Next;

		delete Rear;
		counter--;
		Rear = Iterator;
		Iterator->Next = nullptr;
	}

	num_elements--;
}

template<typename Type>
const Type SinglyLinkedList<Type>::getFront() const
{
	if(isEmpty())
	{
		cerr<<"The linked list is empty. Program will end.\n";
		exit(1);
	}

	return Head->data;
}

template<typename Type>
const Type SinglyLinkedList<Type>::getRear() const
{
	if(isEmpty())
	{
		cerr<<"The linked list is empty. Program will end.\n";
		exit(1);
	}

	return Rear->data;
}

template<typename Type>
bool SinglyLinkedList<Type>::contains(const Type & Item) const
{
	Node<Type> * Iterator1 = Head;

	while(Iterator1 != nullptr && !(Iterator1->data == Item))
		Iterator1 = Iterator1->Next;

	return Iterator1 != nullptr;
}

template<typename Type>
void SinglyLinkedList<Type>::destroy()
{
	Iterator = Head;

	while(Iterator !=nullptr)
	{
		Head = Head->Next;
		delete Iterator;
		counter--;
		Iterator = Head;
	}
	Rear = nullptr;
	Iterator = nullptr;
	num_elements = 0;
}

template<typename Type>
SinglyLinkedList<Type>::~SinglyLinkedList()
{
	destroy();
}

template<typename Type>
void SinglyLinkedList<Type>::printBackward(ostream& out)const
{
	/**
	*Run a loop with in a loop. The outer loop must be a count controlled
	* and run for the number of times num_elements (size of the list). The
	*inner loop must move an iterator to number of locations dictated
	*by outer loop.
	*/

	for(int index = num_elements; index>0; index--)
	{
		Node<Type>* Iterator1 = Head;

		int count = index;
		while(--count)
			Iterator1 = Iterator1->Next;
		out<<Iterator1->data<<"  ";
	}
	out<<endl;
}

template<typename Type>
const Node<Type> * SinglyLinkedList<Type>::getNode(Type value) const
{
	Node<Type> * Iterator1 = Head;
	Node<Type> * Result = nullptr;

	while(Iterator1 != nullptr)
	{
		if(Iterator1->data == value)
		{
			Result = Iterator1;
			break;
		}
		Iterator1 = Iterator1->Next;
	}

	return Result;
}

template<typename Type>
const Node<Type> * SinglyLinkedList<Type>::
nodeBefore(const Node<Type> * Some_Node) const
{
	if(Some_Node != nullptr && Some_Node != Head)
	{
		Node<Type> * Previous = Head;

		while(Previous->Next != Some_Node)
			Previous = Previous->Next;
		return Previous;
	}
	else
		return nullptr;
}

template<typename Type>
void SinglyLinkedList<Type>::addAfter(Type obj, Type target)
{
	if(contains(target) && !contains(obj))
	{
		Node<Type> * itemNode = getNode(target);
		Node<Type> * newNode = new Node<Type>(obj, itemNode->Next);
		counter++;
		itemNode->Next = newNode;
		num_elements++;

		if(Rear == itemNode)
			Rear = newNode;
	}
}

template<typename Type>
void SinglyLinkedList<Type>::addBefore(Type obj, Type target)
{
	if(contains(target) && !contains(obj))
	{
		Node<Type> * itemNode = getNode(target);
		Node<Type> * newNode = new Node<Type>(obj, itemNode);
		counter++;

		if(Head == itemNode)
			Head = newNode;
		else
		{
			Node<Type> * beforeNode = nodeBefore(itemNode);
			beforeNode->Next = newNode;
		}

		num_elements++;
	}
}

template<typename Type>
const Type SinglyLinkedList<Type>::elementAfter(Type target) const
{
	if(!contains(target) || (getNode(target) == Rear))
	{
		cerr<<"The value "<<target<<" is not in the list or is "
			<<"the last value in the list. Exiting the program.\n";
		exit(1);
	}

	return ((getNode(target))->Next)->data;
}

template<typename Type>
const Type SinglyLinkedList<Type>::elementBefore(Type target) const
{
	if(!contains(target) || (getNode(target) == Head))
	{
		cerr<<"The value "<<target<<" is not in the list or is "
			<<"the first value in the list. Exiting the program.\n";
		exit(1);
	}

	return (nodeBefore(getNode(target)))->data;
}

template<typename Type>
void SinglyLinkedList<Type>::getList(istream& in, int flag)
{
	bool done = false;
	if(flag==1)
	{
		cout<<"The data will be added to the Head (front) of linked list.\n";
		while(!done)
		{
			Type temp = Type();
			cout<<"Enter the data item to be added to linked list : ";
			cin>>temp;
			addFront(temp);
			cout<<"More data? enter 0 to continue or 1 to exit : ";
			cin>>done;
		}
	}
	else if(flag == 2)
	{
		cout<<"The data will be added to the Rear of linked list.\n";
		while(!done)
		{
			Type temp = Type();
			cout<<"Enter the data item to be added to linked list : ";
			cin>>temp;
			addRear(temp);
			cout<<"More data? enter 0 to continue or 1 to exit : ";
			cin>>done;
		}
	}
	else if(flag == 3)
		in>>*this;
	else
		cerr<<"Illegal value of the flag is entered.\n";
}

template<typename Type>
istream& operator >>(istream& in,  SinglyLinkedList<Type>& SL)
{
	Type temp = Type();

	in.peek();

	while(!in.eof())
	{
		in>>temp;
		SL.addRear(temp);
	}

	return in;
}

template<typename Type>
void print(Node<Type>* Iterator1, ostream & out)
{	
	if(Iterator1 !=nullptr)	
	{		
		out<<Iterator1->data<<"  ";		
		print(Iterator1->Next, out);	
	}
}

template<typename Type>
void SinglyLinkedList<Type>::printForwardRecursively(ostream& out)const
{	
	Node<Type> * Iterator1 = Head;	
	print(Iterator1,out);	
	cout<<endl;
}

#endif