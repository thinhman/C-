#pragma once
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ItemType
{
public:
	int Integer;
	unsigned int uint;
	unsigned long ulong;
	unsigned short ushort;
	float Float;
	char Character;
	long Long;
	double Double;
	short Short_Integer;
	long double Long_Double;
	bool boolean_data;
	string string_data;
	ItemType()
	{
		ushort = 0;
		uint = 0;
		ulong = 0;
		Integer = 0;
		Float = 0.0f;
		Character = ' ';
		Long = 0;
		Double = 0.0;
		Short_Integer = 0;
		Long_Double = 0.0;
		boolean_data = false;
		string_data = "";
	}

};
#endif