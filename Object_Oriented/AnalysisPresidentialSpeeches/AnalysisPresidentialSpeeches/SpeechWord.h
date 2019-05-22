#pragma once
#ifndef SPEECHWORD_H
#define SPEECHWORD_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class SpeechWord
{
private:
	string word;
	int frequency;
public:
	SpeechWord(const string & wrd = "");
	//Operators overloaded
	friend bool operator < (const SpeechWord & left, const SpeechWord & right)
	{
		return left.word<right.word;
	}

	friend bool operator >(const SpeechWord & left, const SpeechWord & right)
	{
		return left.word>right.word;
	}

	friend bool operator <= (const SpeechWord & left, const SpeechWord & right)
	{
		return left.word <= right.word;
	}

	friend bool operator >= (const SpeechWord & left, const SpeechWord & right)
	{
		return left.word >= right.word;
	}

	friend bool operator == (const SpeechWord & left, const SpeechWord & right)
	{
		return left.word == right.word;
	}

	friend bool operator != (const SpeechWord & left, const SpeechWord & right)
	{
		return left.word != right.word;
	}

	//overload ostream friend function

	friend ostream & operator << (ostream & out,  const SpeechWord & WD)
	{
		out << WD.word << " : "<< WD.frequency <<" times";
		return out;
	}
	static void convertToLowerCase(string & str);
	void updateFequency();
	~SpeechWord()
	{
	
	}
};

#endif