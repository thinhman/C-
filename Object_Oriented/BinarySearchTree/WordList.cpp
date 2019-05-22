#include "WordList.h"
const SinglyLinkedList<int> WordList::getList()
{
	return LineNumList;
}

string WordList::getWord()
{
	return Word;
}

bool WordList::operator< (WordList WL)
{

	if (Word < WL.Word)
	{
		return true;
	}
	return false;
}

bool WordList::operator== (WordList WL)
{
	if (Word == WL.Word)
	{
		return true;
	}
	return false;
}

bool WordList::operator > (WordList W)
{
	if (Word > W.Word)
	{
		return true;
	}
	return false;
}

void WordList::setList(SinglyLinkedList< int > L)
{
	LineNumList = L;
}

void WordList::setWord(string W)
{
	Word = W;
}
void WordList::addToList(int lineNum)
{
	LineNumList.addFront(lineNum);
}
