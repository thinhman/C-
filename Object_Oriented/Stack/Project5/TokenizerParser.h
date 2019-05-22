#pragma once
#ifndef TOKENIZER_PARSER_H
#define TOKENIZER_PARSER_H

#include <string>
#include <cstring>    // for strchr
#include <list>
#include <map>
#include <iostream>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

/**
*@author Satish Singhal Ph. D.
*@version 1.0<BR><BR>
*<B>Class Description</B><BR>
*The class TokenizerParser has some basic static functions
*that will help you to reduce the amount of code  you will need to
*write in experiment 4. The documentation gives you the
*details of various member functions. The functions either
*tokenize a STL string and return to you the number of space
*delimited tokens in your postfix espression or parse the
*neumeric strings for you. An example of using the class
*TokenizerParser is show below.<BR>
*<B>The main function</B><BR><BR>
*#include "TokenizerParser.h"<BR>
*const int MAX = 200;<BR>

*void main()<BR>
*{<BR>
string num = string("-.33");<BR>
double val = TokenizerParser::parseDouble(num);<BR>
cout<<val<<endl;<BR>
int value = TokenizerParser::parseInt(string("-35"));<BR>
cout<<value<<endl;<BR>
long num1 = TokenizerParser::parseLong(string("-200000000"));<BR>
cout<<num1<<endl;<BR>
string Str_Arr[MAX];<BR>
string exp = " 4 2 + 3 5 1 - * + ";<BR>
int count = 0;<BR>
TokenizerParser::getStringArray(Str_Arr,exp,MAX,count);<BR>
for(int index=0; index<count; index++)<BR>
cout<<Str_Arr[index]<<endl;<BR>
cout<<endl;<BR>
}<BR><BR>

<B> Output From Above main</B><BR>
-0.33<BR>
-35<BR>
-200000000<BR>
4<BR>
2<BR>
+<BR>
3<BR>
5<BR>
1<BR>
-<BR>
*<BR>
+<BR>
*/

namespace MySpace
{
	bool isws(char c, char const * const wstr = " \t\n");
}

class TokenizerParser
{
protected:
	/**
	*Function is protected. So it is not to be called by the client.
	*/
	static void stringtok(list<string> &l, string const &s, char const * const ws = " \t\n");
public:
	/**
	*The function takes a string expression as an argument and returns
	*an array of tokens after stripping the white spaces from it.
	*Whitespaces may be tabs, newlines and blank characters.
	*For example if a string such as "Hello World I am here + you are there" is
	*sent to the function to be tokenized, then it will return by reference
	*an array with following strings in them:<BR>
	*Hello<BR>
	*World<BR>
	*I<BR>
	*am<BR>
	*here<BR>
	*+<BR>
	*you<BR>
	*are<BR>
	*there<BR>
	*The description of various parameters is as follows:<BR>
	*@param Str_Arr is the array of strings that contains the tokens extracted
	*from the string expression exp.
	*@param exp is the string to be tokenized. It may contain words or
	*alphanumeric characters and mathematical or logical operators.
	*@param MAX is the physical length of the array. <B>It is client's respnsibilty
	*to ascertain that number of tokens in the expression exp are smaller than
	*the physical length of the array Str_Arr. If physical length MAX is
	*smaller than the number of tokens to be extracted from the expression exp, then
	*token loss will take place.</B>
	*@param count is the number of tokens extracted from the string exp. The
	*maximum value of count is MAX. count is also the logical length of array
	* Str_Arr.
	*/
	static void getStringArray(string Str_Arr[], const string& exp, size_t MAX, size_t &count);
	/**
	*The function parses the string form of a double type number passed to it
	*and returns its double value.
	*<B>It is client's responsibility to make sure that string passed to
	*the function contains a valid double data type. Invalid data type will
	*give unpredictable results</B>.
	*@param val is the string to be parsed into a double value.
	*@return the double value of string val.
	*/
	static double parseDouble(string &val);
	/**
	*The function parses the string form of a integer type number passed to it
	*and returns its int value.
	*<B>It is client's responsibility to make sure that string passed to
	*the function contains a valid int data type. Invalid data type will
	*give unpredictable results</B>.
	*@param val is the string to be parsed into a int value.
	*@return the int value of string val.
	*/
	static int parseInt(string &val);
	/**
	*The function parses the string form of a long type number passed to it
	*and returns its long value.
	*<B>It is client's responsibility to make sure that string passed to
	*the function contains a valid long data type. Invalid data type will
	*give unpredictable results</B>.
	*@param val is the string to be parsed into a long value.
	*@return the long value of string val.
	*/
	static long parseLong(string &val);
};

#endif