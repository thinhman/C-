#pragma once
#include "linkedlistinterface.h"
using namespace std;


class WordList
{
private:

	string Word;
	SinglyLinkedList<int>  LineNumList;

public:
	
	friend istream & operator >> (istream & in, WordList & WL)
	{
		if (&in == &cin)
		{
			cout << "Enter word for WorldList: ";
			cin >> WL.Word;
		}

		else if (&in == &in)
		{
			in >> WL.Word;
		}
		return in;
	}
	friend ostream & operator << (ostream & out, WordList & WL)
	{
		out << WL.Word << " ";
		WL.LineNumList.printBackward(out);

		return out;
	}
	WordList() { }
	virtual ~WordList() { }
	const SinglyLinkedList<int> getList();
	string getWord();
	bool operator < (WordList WL);
	bool operator == (WordList WL);
	bool operator > (WordList WL);
	void setList(SinglyLinkedList<int> L);
	void setWord(string W);
	void WordList::addToList(int lineNum);


	
};


