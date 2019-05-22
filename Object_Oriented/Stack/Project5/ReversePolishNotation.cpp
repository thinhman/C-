#include "ReversePolishNotation.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//-----------------------------------------
ReversePolishNotation::ReversePolishNotation(const string &input,
	const string &output) : outputString(output)
{
	setInput(input);
}
//----------------------------------------
//---------------------------------------------
const string& ReversePolishNotation::getInput() const
{
	return inputString;
}
//------------------------------------------------
void ReversePolishNotation::setInput(const string& input)
{
	inputString = "";
	inputString += '[';
	inputString += input;
	inputString += ']';
}
//-------------------------------------------------
const string& ReversePolishNotation::getOutput() const
{
	return outputString;
}
//---------------------------------------------------
void ReversePolishNotation::setOutput(const string& output)
{
	outputString = output;
}
//----------------------------------------------------
int ReversePolishNotation::priority(char s)
{
	int operatorPriority = -1;

	if (s == '[')
		operatorPriority = 0;
	else if (s == '(')
		operatorPriority = 1;
	else if (s == '+')
		operatorPriority = 2;
	else if (s == '-')
		operatorPriority = 2;
	else if (s == '*')
		operatorPriority = 3;
	else if (s == '/')
		operatorPriority = 3;
	else if (s == '^')
		operatorPriority = 4;
	else if (s == '~')
		operatorPriority = 5;

	return(operatorPriority);
}
//---------------------------------------
void ReversePolishNotation::convert()
{
	Stack myStack;
	char nextCharacter = ' ';
	char topOfStack = ' ';
	size_t len = inputString.length();

	for (size_t i = 0; i < len; i++)
	{
		nextCharacter = inputString[i];
		if (MySpace::isws(nextCharacter))
		{
			continue;
		}
		if (nextCharacter == ')')
		{
			try
			{
				topOfStack = (myStack.top()).Character;
			}
			catch (string e)
			{
				throw string("String is not parenthetically balanced (missing \"(\")");
			}
			myStack.pop();
			while (!(topOfStack == '('))
			{
				outputString += " ";
				outputString += topOfStack;
				try
				{
					topOfStack = (myStack.top()).Character;
				}
				catch (string e)
				{
					throw string("String is not parenthetically balanced (missing \"(\")");
				}
				myStack.pop();
			}
		}
		else if (nextCharacter == ']')
		{
			try
			{
				topOfStack = (myStack.top()).Character;
			}
			catch (string e)
			{
				throw string("String is not parenthetically balanced (missing \"[\")");
			}
			myStack.pop();
			while (!(topOfStack == '['))
			{
				if (topOfStack == '(')
				{
					throw string("String is not parenthetically balanced (missing \")\")");
				}
				outputString += " ";
				outputString += topOfStack;
				try
				{
					topOfStack = (myStack.top()).Character;
				}
				catch (string e)
				{
					throw string("String is not parenthetically balanced (missing \"[\")");
				}
				myStack.pop();
			}
		}
		else if (nextCharacter == '(' || nextCharacter == '[')
		{
			ItemType data;
			data.Character = nextCharacter;
			myStack.push(data);
		}
		else if (nextCharacter == '*' || nextCharacter == '/' ||
			nextCharacter == '^')
		{
			processOperator(myStack, nextCharacter);
		}
		else if (nextCharacter == '+' || nextCharacter == '-')
		{
			if (isUnary(inputString, i))
			{
				size_t j = i;
				while (++j < len && MySpace::isws(inputString[j]))
				{
				}
				if (j == len)
				{
					throw string("Invalid expression");
				}
				char nextCh = inputString[j];
				if (isdigit(nextCh) || nextCh == '.')
				{
					outputString += " ";
					outputString += extractNumber(inputString, i);
					i--;
				}
				else if (isalpha(nextCh) || nextCh == '(' || nextCh == '[')
				{
					if (nextCharacter == '-')
					{
						processOperator(myStack, '~'); //The program uses ~ for unary negation oparator.
					} //if nextCharacter is unary + the program will simply skip it.
				}
				else
				{
					throw string("Invalid expression");
				}
			}
			else
			{
				processOperator(myStack, nextCharacter);
			}
		}
		else if (isalpha(nextCharacter))
		{
			outputString += " ";
			outputString += nextCharacter;
		}
		else if (isdigit(nextCharacter) || nextCharacter == '.')
		{
			outputString += " ";
			outputString += extractNumber(inputString, i);
			i--;
		}
		else
		{
			throw string("Invalid character");
		}
	}
	if (!myStack.isEmpty())
	{
		throw string("String is not parenthetically balanced (missing \"]\")");
	}
}
//---------------------------------------
void ReversePolishNotation::processOperator(Stack &stk, char opr)
{
	char topOfStack = ' ';
	try
	{
		topOfStack = (stk.top()).Character;
	}
	catch (string e)
	{
		throw string("String is not parenthetically balanced (missing \"[\")");
	}
	while (priority(opr) <= priority(topOfStack))
	{
		stk.pop();
		outputString += " ";
		outputString += topOfStack;
		try
		{
			topOfStack = (stk.top()).Character;
		}
		catch (string e)
		{
			throw string("String is not parenthetically balanced (missing \"[\")");
		}
	}
	ItemType data;
	data.Character = opr;
	stk.push(data);
}
//---------------------------------------
string ReversePolishNotation::extractNumber(const string &source, size_t &idx)
{
	bool hasPoint = false; //to make sure that only one '.' is added to the number
	string out = "";
	size_t len = source.length();
	if (idx >= len)
	{
		throw string("Starting index beyond source string length");
	}
	if (source[idx] == '-')
	{
		out += '-';
		while (++idx < len && MySpace::isws(source[idx]))
		{
		}
	}
	else if (source[idx] == '+')
	{
		while (++idx < len && MySpace::isws(source[idx]))
		{
		}
	}

	if (idx == len)
	{
		throw string("Invalid number format");
	}
	if (source[idx] == '.')
	{
		hasPoint = true;
		out += '0';
		out += '.';
		idx++;
		if (idx == len)
		{
			throw string("Invalid number format");
		}
	}
	if (isdigit(source[idx]))
	{
		out += source[idx];
	}
	else
	{
		if (hasPoint)
		{
			throw string("Invalid number format");
		}
		else
		{
			throw string("Invalid expression");
		}
	}
	while (++idx < len && isdigit(source[idx]))
	{
		out += source[idx];
	}
	if (idx == len)
	{
		return out;
	}
	if (source[idx] == '.')
	{
		if (hasPoint)
		{
			removeTrailingPoint(out);
			return out;
		}
		else
		{
			out += '.';
			hasPoint = true;
			while (++idx < len && isdigit(source[idx]))
			{
				out += source[idx];
			}
			if (idx == len)
			{
				return out;
			}
		}
	}
	if (source[idx] == 'e' || source[idx] == 'E')
	{
		removeTrailingPoint(out);
		out += 'e';
		idx++;
		if (idx == len)
		{
			throw string("Invalid number format");
		}
		if (source[idx] == '+' || source[idx] == '-')
		{
			out += source[idx];
			idx++;
			if (idx == len)
			{
				throw string("Invalid number format");
			}
		}
		else
		{
			out += '+';
		}
		if (isdigit(source[idx]))
		{
			out += source[idx];
		}
		else
		{
			throw string("Invalid number format");
		}
		while (++idx < len && isdigit(source[idx]))
		{
			out += source[idx];
		}
	}
	removeTrailingPoint(out);
	return out;
}
//---------------------------------------
bool ReversePolishNotation::isUnary(const string &source, size_t idx)
{
	while (MySpace::isws(source[--idx]))
	{
	}
	return MySpace::isws(source[idx], "([+-*/^");
}
//---------------------------------------
void ReversePolishNotation::removeTrailingPoint(string &s)
{
	size_t len = s.length();
	if (len && s[--len] == '.')
	{
		s.resize(len);
	}
}