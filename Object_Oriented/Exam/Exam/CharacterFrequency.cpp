//Thinh Nguyen 
#include "CharacterFrequency.h"
int CharacterFrequency::getfre()
{
	return frequency;
}
char CharacterFrequency::getletter()
{
	return letter;
}
CharacterFrequency::CharacterFrequency(char Letter, int Frequency)
{
	this->frequency = Frequency;
	this->letter = toupper(Letter);
}
/////////////////////////////////////////////////////////////////////////////////
void CharacterFrequency::updateFequency()
{
	this->frequency++;
}

////////////////////////////////////////////////////////////////////////////////
void CharacterFrequency::convertToUpperCase(char & text)
{
	char temp;
	temp = text;
	toupper(temp);
	text = temp;

}