#pragma once
#ifndef DICTIONARYNODE_H
#define DICTIONARYNODE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
/*
Dictionarynode is a node for Dictionary data structure. Each node contains a word, its meaning and address
to the next node.
*/
struct DictionaryNode
{
	string word;
	string meaning;
	DictionaryNode * Next;
	DictionaryNode(string wrd = "Word not set", string mean = "Meaning not set", 
		DictionaryNode * nxt = nullptr) :word(wrd), meaning(mean), Next(nxt)
	{
		//From Dictionary Node Constructor
	}

	~DictionaryNode()
	{
		//From DictionaryNode destructor
	}

	friend ostream & operator<<(ostream & out, const DictionaryNode & DN)
	{
		if (&out == &cout)//Print to console
		{
			cout << "Word: " << DN.word << endl
				<< "Means: " << DN.meaning << endl;
		}
		else //Print to file
		{
			out << "Word: " << DN.word << endl
				<< "Means: " << DN.meaning << endl;
		}

		return out;
	}
};
#endif