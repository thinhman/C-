#pragma once
#ifndef LETTERFREQUENCYLIST_H
#define LETTERFREQUENCYLIST_H
#include "LetterNode.h"

class LetterFrequencyList
{
private:
	LetterNode * HeadPtr;
public:
	bool contains(char ltr);
	LetterFrequencyList();// Constructor
	LetterFrequencyList(const LetterFrequencyList & other); // Copy constructor
	LetterFrequencyList & operator = (const LetterFrequencyList & other); // Assignment Operator
	virtual ~LetterFrequencyList(); // Destructor
	const string toString() const;
	void insert(char ltr, size_t frq);
	void insertInOrder(char & ltr);
	void destroy();
	void copy(const LetterFrequencyList & other);
	
	
};
#endif
