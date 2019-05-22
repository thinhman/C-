#include "DictionaryLinkedList.h"

DictionaryLinkedList::DictionaryLinkedList() :Head(new DictionaryNode("123", "-123", nullptr))
{
	//cout<<"From constructor of Dictionary Linked  List"<<endl;
}

void DictionaryLinkedList::destroy()
{
	DictionaryNode * Current = Head; // start with dummy node
	while (Current != nullptr){
		// do something
		DictionaryNode *save = Current;
		Current = Current->Next;
		delete save;
	}
}
/////////////////////////
void DictionaryLinkedList::copy(const DictionaryLinkedList & Other)
{
	DictionaryNode *Current = Other.Head->Next;
	DictionaryNode *Iterator = Head = new DictionaryNode("123","-123", nullptr); // create dummy node
	while (Current != nullptr){
		// create a copy of node pointed to by Current, and link up
		Iterator->Next = new DictionaryNode(Current->word,Current->meaning, nullptr); 

		// update pointers
		Current = Current->Next;
		Iterator = Iterator->Next;
	}
}
/////////////////////////////
DictionaryLinkedList::DictionaryLinkedList(const  DictionaryLinkedList & Other)
{
	cout << "From Copy constructor.\n";
	if (this == &Other)
	{
		cout << "Self copying not allowed. Exiting program.\n";
		exit(0);
	}
	copy(Other);
}
//////////////////////////////
const DictionaryLinkedList& DictionaryLinkedList::operator = (const DictionaryLinkedList & Other)
{
	cout << "From assignment operator.\n";
	if (this != &Other)
	{
		destroy();
		copy(Other);
	}

	return *this;
}
///////////////////////
DictionaryLinkedList::~DictionaryLinkedList()
{
	cout << "From destructor.\n";
	destroy();
}
//////////////////////////////////////
bool DictionaryLinkedList::contains(const string & wrd, DictionaryNode  & Node)
{
	
	DictionaryNode *Current = Head->Next;
	string copyWord = wrd;
	convertToUpperCase(copyWord);

	while (Current != nullptr){
		if (Current->word == copyWord)
		{
			Node = *Current;// not a deep copy!
			return true;
		}
		// update pointers
		Current = Current->Next;
	}

	return false;
}
//////////////////////////////////////
void DictionaryLinkedList::InsertInOrder( string & wrd, const string & mean)
{
	DictionaryNode dummy;
	if (!contains(wrd, dummy))
	{
		convertToUpperCase(wrd);
		DictionaryNode * Current = Head;

		while (Current->Next != nullptr && wrd > Current->Next->word)
		{
			Current = Current->Next;
		}

		Current->Next = new DictionaryNode(wrd, mean, Current->Next);
	}
	else
	{
		cout << "The word " << wrd << " is already in the dictionary." << endl;
	}
}
////////////////////////////////////////////
void DictionaryLinkedList::convertToUpperCase(string & text)
{
	string temp = "";

	for (size_t i = 0; i < text.length(); i++)
	{

		if (isalpha(text[i]))
		{
			temp += (toupper(text[i]));
		}
	}

	text = temp;
}

///////////////////////////////////////////
void DictionaryLinkedList::getInstance(istream & in, DictionaryLinkedList & DL)
{
	if (&in == &cin)//User wishes to add words from keyboard
	{
		bool done = false;
		while (!done)
		{
			cout << "Enter the word to be added to the dictionary: ";
			string tempWord;
			cin >> tempWord;
			string mean;
			cout << "Enter the meaning of the word: ";
			cin.sync();
			getline(cin, mean);
			convertToUpperCase(tempWord);
			DL.InsertInOrder(tempWord, mean);
			cout << "More words? Enter 0 to continue or 1 to exit: ";
			cin >> done;
		}
	}
	else{ //Reading from file
		while (in.peek() != EOF)
		{
			string tempWord;
			getline(in, tempWord);
			string mean;
			getline(in, mean);
			convertToUpperCase(tempWord);
			DL.InsertInOrder(tempWord, mean);
		}
	}
}