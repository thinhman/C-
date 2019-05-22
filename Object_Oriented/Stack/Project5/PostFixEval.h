#pragma once
#ifndef POST_FIX_EVAL_H
#define POST_FIX_EVAL_H
#include "ReversePolishNotation.h"
#include <algorithm>

class PostFixEval
{
private:
	string expression;
	bool numeric;
	double value;
	bool isNumeric();
	double evaluate();
	/*bool hasValidValue;
	bool isValidExp;
	string source;
	
	bool isOperator(char c, wstr);*/
public:
	void findValue();
	PostFixEval(string Exp = " ", bool numeric1 = false);
	void print(ostream & out);
	const string getExp();
	const bool getNumeric();
};


#endif