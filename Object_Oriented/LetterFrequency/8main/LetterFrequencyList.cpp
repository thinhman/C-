#include "LetterFrequencyList.h"
LetterFrequencyList::LetterFrequencyList() : HeadPtr(new LetterNode(' ', 0, nullptr))
{
	cout << "\nFrom constructor\n" << endl;
}
LetterFrequencyList::LetterFrequencyList(const LetterFrequencyList & other)
{
	if (this == &other)
	{
		cout << "Self copying not allowed. Exiting program.\n";
		exit(0);
	}
	copy(other);
	cout << "From copy constructor\n";

}
LetterFrequencyList & LetterFrequencyList::operator = (const LetterFrequencyList & other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	
	cout << "From assignment operator\n";
	return *this;

}
LetterFrequencyList::~LetterFrequencyList()
{
	cout << "From Destructor\n";
	destroy();
}
const string LetterFrequencyList::toString() const
{

	if (HeadPtr != nullptr)
	{
		ostringstream os;
		LetterNode *iterator = HeadPtr;
		while (iterator->Next != nullptr)//traverse list and put each node's toString into os
		{
			iterator = iterator->Next;
			os << iterator->toString();

		}
		return os.str();
	}

	else
	{
		throw string("List is empty");
	}
}
void LetterFrequencyList::insertInOrder(char & ltr)
{
	ltr = toupper(ltr);
	LetterNode * current = HeadPtr;
	if (contains(ltr))
	{
		while (current->Next != nullptr && current->letter != ltr)
		{
			current = current->Next;
			if (current->letter == ltr)
			{
				current->frequency++;
			}
		}
	}
	else
	{
		while (current->Next != nullptr && ltr > current->Next->letter) //while its not the end and ltr is still bigger than the next node's letter
		{
			current = current->Next;//moves pointer forward one
		}
		current->Next = new LetterNode(ltr, 1, current->Next);//if it is out of the loop, either ltr is larger than current and smaller than next, so it goes in between, or it goes at the very end
	}
}
void LetterFrequencyList::insert(char ltr, size_t frq)
{
	HeadPtr->Next = new LetterNode(ltr,frq, HeadPtr->Next);
}
void LetterFrequencyList::destroy()
{
	LetterNode * Current = HeadPtr; // start with dummy node
	while (Current != nullptr)
	{
		LetterNode *save = Current;
		Current = Current->Next;
		delete save;
	}
	
}
void LetterFrequencyList::copy(const LetterFrequencyList & other)
{
	LetterNode *Current = other.HeadPtr->Next;
	LetterNode *Iterator = HeadPtr = new LetterNode(' ', 0, nullptr); // create dummy node

	while (Current != nullptr)
	{
		// create a copy of node pointed to by Current, and link up
		Iterator->Next = new LetterNode(Current->letter, Current->frequency, nullptr);
		Current = Current->Next;
		Iterator = Iterator->Next;
	}

}
bool LetterFrequencyList::contains(char ltr)
{

	LetterNode *Current = HeadPtr->Next;
	char copyLetter = ltr;
	toupper(copyLetter);

	while (Current != nullptr)
	{
		if (Current->letter == copyLetter)
		{
			//LetterNode  A = *Current;// not a deep copy!
			return true;
		}
		// update pointers
		Current = Current->Next;
	}

	return false;
}

