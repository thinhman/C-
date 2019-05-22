#pragma once
#ifndef REVERSE_POLISH_NOTATION_H
#define REVERSE_POLISH_NOTATION_H

#include <string> 
#include "TokenizerParser.h"
#include "Stack.h"

using namespace std;

/**
*Class <code>ReversePolishNotation</code> accepts a user inputted
*infix expression which must be parenthetically balanced and outputs
*its postfix form. Postfix form is easier to evaluate as it needs no
*parenthesis.
*/
class ReversePolishNotation
{
private:
	/**
	*The field inputString will be the user inputted string for the
	*infix expression.
	*/
	string inputString;
	/**
	*The field outputString will be the form converted to postfix
	*outputted for the user.
	*/
	string outputString;
	/**
	*The function priority takes an operator character as an input and
	*returns the integer indicating the priority for that operator. C++
	*operator priority chart is followed in the function design.
	*@param character s is the operator in the infix expression.
	*@return the priority number for the operator based on C++ operator
	*precedence.
	*/
	int priority(char s);
	/**
	*Returns true if current operator must act as a unary operator.
	*NOTE: It assumes that the current character is a '+' or '-'
	*@param source is the string that contains the operator to be checked.
	*@param idx is the index of operator to be checked in source string.
	*/
	bool isUnary(const string &source, size_t idx);
	/**
	*Executes the post fix conversion algorithm for operators.
	*@param stk is the stack to be used during conversion.
	*@param opr is the operator to be processed.
	*/
	void processOperator(Stack &stk, char opr);
	static void removeTrailingPoint(string &s);
public:
	/**
	*The default and explicit constructor.
	*@param input has the default value of null string, and explicit value of
	*user inputted infix expression.
	*@param output has a default value of null string or any user inputted value.
	*/
	ReversePolishNotation(const string &input = "", const string &output = "");
	/**
	*Accessor function to get the inputted string.
	*@returns the inputString member of class <code>ReversePolishNotation</code>
	*/
	const string& getInput() const;
	/**
	*Sets the data member inputString to the value passed to the function.
	*@param input is the new value of the data member inputString.
	*/
	void setInput(const string &input);
	/**
	*Accessor function to get the output.
	*@returns the outputString member of class <code>ReversePolishNotation</code>
	*/
	const string& getOutput() const;
	/**
	*Sets the data member outputString to the value passed to the function.
	*@param input is the new value of the data member outputString.
	*/
	void setOutput(const string &output);
	/**
	*The function convert takes the inputtted infix expression as a STL
	*string and generates its postfix form and stores the result in the
	*data member outputString. The program uses ~ for unary negation oparator.
	*/
	void convert();
	/**
	*Trys to extract a floating point number as an string from the source string beginning
	at idx. Throws an exception if there is not a valid floating point number immidiately
	starting at idx or idx is not whithin source length.
	*@param source is the string to extract floating point number from.
	*@param idx is the index in source string to start extraction from. Upon successful
	execution inx contains the index of the first character after the number.
	*/
	static string extractNumber(const string &source, size_t &idx);
};

#endif
