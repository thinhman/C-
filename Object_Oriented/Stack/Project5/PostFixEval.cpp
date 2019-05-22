#include "PostFixEval.h"

PostFixEval::PostFixEval(string Exp, bool numeric1) : expression(Exp), numeric(numeric1)
{
	if (isNumeric() == true)
	{
		numeric1 = false;
	}
	else if (isNumeric() == false)
	{
		numeric1 = true;
	}
	value = 0;

}
bool PostFixEval::isNumeric() 
{
	/*bool Numeric = true;
	string Str_Arr[MAX];
	char nextCharacter = ' ';
	size_t count;
	TokenizerParser::getStringArray(Str_Arr, getExp() , MAX, count);
	for (size_t i = 0; i < count; i++)
	{
		nextCharacter = Str_Arr[i].c_str();
		if (!isdigit(int(nextCharacter)))
		{
			Numeric = false;			
		}
		break;
	}*/
	return any_of(expression.begin(), expression.end(), isalpha);
}
const string PostFixEval::getExp()
{
	return expression;
}
const bool PostFixEval::getNumeric()
{
	return numeric;
}
