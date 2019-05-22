#include "SpeechWord.h"

SpeechWord::SpeechWord(const string & wrd)
{
	string copy = wrd;
	convertToLowerCase(copy);
	this->word = copy;
	frequency = 1;
}
/////////////////////////////////////////////////////////////////////////////////
void SpeechWord::updateFequency()
{
	this->frequency++;
}

////////////////////////////////////////////////////////////////////////////////
void SpeechWord::convertToLowerCase(string & text)
{
	string temp = "";

	for (size_t i = 0; i < text.length(); i++)
	{
		temp += (tolower(text[i]));
	}

	text = temp;
}