#include "TokenizerParser.h"

namespace MySpace
{
	bool isws(char c, char const * const wstr)
	{
		return (strchr(wstr, c) != NULL);
	}
}

void TokenizerParser::stringtok(list<string> &l, string const &s, char const * const ws)
{
	const string::size_type  S = s.size();
	string::size_type  i = 0;

	while (i < S) {
		// eat leading whitespace
		while ((i < S) && (MySpace::isws(s[i], ws)))  ++i;
		if (i == S)
		{
			return;  // nothing left but WS
		}
		// find end of word
		string::size_type  j = i + 1;
		while ((j < S) && (!MySpace::isws(s[j], ws)))
		{
			++j;
		}
		// add word
		l.push_back(s.substr(i, j - i));

		// set up for next loop
		i = j + 1;
	}
	//while (i < S) {
	//    // eat leading whitespace
	//    while ((i < S) && (MySpace::isws(s[i],ws)))
	//    { 
	//        ++i;
	//    }
	//    if (i == S)  return;  // nothing left but WS

	//    // find end of word
	//    string::size_type  j = i+1;
	//    while ((j < S) && (!MySpace::isws(s[j],ws)))  ++j;

	//    // add word
	//    l.push_back(s.substr(i,j-i));

	//    // set up for next loop
	//    i = j+1;
	//}
}
/////////////////////////////////////////////////////////
void TokenizerParser::getStringArray(string Str_Arr[], const string &exp, size_t MAX, size_t &count)
{
	list<string> TokenList;
	stringtok(TokenList, exp);
	list<string>::const_iterator it = TokenList.begin();
	size_t index = 0;
	count = 0;
	for (; it != TokenList.end() && index < MAX; ++it)
	{
		Str_Arr[index++] = *it;
		count++;
	}
}
////////////////////////////////////////////////////////////
double TokenizerParser::parseDouble(string &val)
{
	return atof(val.c_str());
}
/////////////////////////////////////////////////////////
int TokenizerParser::parseInt(string &val)
{
	return atoi(val.c_str());
}
/////////////////////////////////////////////////////////
long TokenizerParser::parseLong(string &val)
{
	return atol(val.c_str());
}