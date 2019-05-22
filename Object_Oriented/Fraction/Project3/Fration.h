#pragma once
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

class Fraction
{
private:
	long numerator;
	long denomenator;
public:
	Fraction(long numerator = 0, long denominator = 1);
	long gcd(long a, long b);
	const string toString();
	const long getBottom()const;
	const long getTop()const;
	void normalize();
	const Fraction operator-();
	const Fraction operator--();
	const Fraction operator--(int maker);
	const Fraction operator++();
	const Fraction operator++(int maker);
	double toDouble();
	friend const Fraction operator+ (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator- (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator * (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator/ (const Fraction & num1, const Fraction & num2);
	friend bool operator== (const Fraction & num1, const Fraction & num2);
	friend bool operator!= (const Fraction & num1, const Fraction & num2);
	friend ostream & operator<< (ostream & output, const Fraction & num);
	friend istream & operator>> (istream & input, Fraction & num);
};


#endif

