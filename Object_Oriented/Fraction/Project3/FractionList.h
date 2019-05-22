#pragma once
#ifndef FRACTIONLIST_H
#define FRACTIONLIST_H
#include "Fration.h"

class FractionList
{
private:
	const static int MAX = 30;
	Fraction List[MAX];
	bool isSorted;
	size_t num_elements;
public:
	FractionList();
	void addFraction(const Fraction & F);
	size_t getNumberOfElements()const;
	static void getInstance(FractionList & FL);
	/*
	const Fraction getLargest();
	double getMeanOfFractions();
	
	const Fraction getSmallest();
	bool getSortedState();
	const Fraction getSumOfFractions();
	
	
	const Fraction & operator [] (size_t index)const;
	*/
	bool isEmpty();
	bool isFull();
	void sort();
	const string toString();
	friend ostream & operator << (ostream & out, const FractionList & FL);
	friend istream & operator >> (istream & in, FractionList & FL);
};
#endif