#pragma once
#ifndef DICTIONARYLINKEDLIST_H
#define DICTIONARYLINKEDLIST_H
#include "DictionaryNode.h"
/*
DictionaryLinkedList is a class that stores words and their meaning (just one meaning for now).
Like a normal dictionary, the DictionaryLinkedList objects are sorted in ascending order.
Also the objects of class DictionaryLinkedList behave like a mathematical set.
Just like a dictionary would store different words (A word will not be repeated), the
DictionaryLinkedList objects also behave like a mathematical set in the sense that
word is entered only once. The insert functionality checks for existing words and
only adds a new word if it is not present in the list. It has has functionalities
for printing the dictionary, to file or keyboard or build dictionary from an input file
or by keyboard data entry.

Functionaties to be added in future versions:
1. Functionality to update the meaning of a word already stored.
2. Merge two dictionaries together.
3. Get number of words in the dictionary.
4. Return by reference an array of size 26 where each array member stores number of words
starting with certain letter in ascending order. For example first array member will store # of words
starting with A, second with B and so on.
5. Compare two dictioanries (overload == operator) and return true if they are 
identical otherwise return false.
6. Overload != operator.
7. GUI version in C# or in C++.
*/
struct DictionaryLinkedList
{
	DictionaryNode * Head;
	DictionaryLinkedList();
	//Rule of three
	void destroy();
	void copy(const DictionaryLinkedList & Other);
	DictionaryLinkedList(const  DictionaryLinkedList & Other);
	const DictionaryLinkedList& operator = (const DictionaryLinkedList & Other);
	~DictionaryLinkedList();
	bool contains(const string & wrd , DictionaryNode  & Node);
	
	static void getInstance(istream & in, DictionaryLinkedList & DL);
	static void convertToUpperCase(string & text);
	friend ostream & operator <<(ostream & out, const DictionaryLinkedList & DL)
	{
		DictionaryNode * Current = DL.Head->Next;

		while (Current != nullptr)
		{
			out << "------------------------------------" << endl;
			out << *Current;
			out << "------------------------------------" << endl;
			Current = Current->Next;
		}

		return out;
	}
private:
	void InsertInOrder( string & wrd, const string & mean);
};
#endif