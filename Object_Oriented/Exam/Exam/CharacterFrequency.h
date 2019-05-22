//Thinh Nguyen
#pragma once
#ifndef CHARACTERFREQUENCY_H
#define CHARACTERFREQUENCY_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CharacterFrequency
{
private:
	char letter;
	int frequency;
public:
	char getletter();
	int getfre();
	CharacterFrequency(char Letter = '0', int freq = 1);
	//Operators overloaded
	friend bool operator < (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.letter<right.letter;
	}

	friend bool operator >(const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.letter>right.letter;
	}

	friend bool operator <= (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.letter <= right.letter;
	}

	friend bool operator >= (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.letter >= right.letter;
	}

	friend bool operator == (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.letter == right.letter;
	}

	friend bool operator != (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.letter != right.letter;
	}

	//overload ostream friend function

	friend ostream & operator << (ostream & out, const CharacterFrequency & cf)
	{
		out << cf.letter << " : " << cf.frequency << " times";
		return out;
	}
	static void convertToUpperCase(char & ch);
	void updateFequency();
	~CharacterFrequency()
	{

	}
};

#endif
