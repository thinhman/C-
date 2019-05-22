#pragma once
#ifndef LETTERNODE_H
#define LETTERNODE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct LetterNode
{
	size_t frequency;
	char letter;
	LetterNode * Next;
	LetterNode(char ch = ' ', size_t frq = 0, LetterNode * ptr = nullptr) : letter(ch), frequency(frq), Next (ptr)
	{
	}
	const string toString() const
	{
		ostringstream os;
		os << "Letter " << letter << " Frequency " << frequency << endl;
		return os.str();

	}
};
#endif
