#include "iterator.h"
#include "SpeechWord.h"
#include <sstream>
#include <iostream>
using namespace std;
/*
This program analyzes presidential speeches to see how frequently president used certain
words in his speeches. Press reporters sometime get an idea about presidential thoughts,
policies and plans by doing this kind of analysis.
*/
const int MAX = 2000;
void convertToLowerCase(string & text);
bool Contains(string arr[], string wrd, int length);
int main()
{
	cout << "The program will analyze presidential speeches for frequency of certain words: " << endl;
		cout << "Enter full path to input file : ";
		string filename;
		getline(cin, filename);
		ifstream in(filename);

		if (!in.is_open()){
			cout << "File opening error" << endl;
			exit(0);
		}

	//Now we read the words we are interested in into a vector
	//Vector will serve as our map
	string AnalyzedWords[MAX];
	cout << "Enter full path to file for words to be analyzed: ";
	string analyzedWordsFileName;
	cin.sync();
	getline(cin, analyzedWordsFileName);
	ifstream inWords(analyzedWordsFileName);

	if (!inWords.is_open()){
		cout << "File opening error" << endl;
		exit(0);
	}
	int count = 0;

	while (inWords.peek() != EOF && count<MAX)
	{
		string wrd;
		inWords >> wrd;
		AnalyzedWords[count] = wrd;
		count++;
	}

	BinarySearchTree<SpeechWord> BST_SpeechWords;

	while (in.peek() != EOF)
	{
		string foo;
		in >> foo;
		//is foo contained in words of interest vector?

		if (Contains(AnalyzedWords, foo, count) && foo.length()>2)
		{
			SpeechWord SW(foo);

			//does tree already contain SW?

			if (BST_SpeechWords.contains(SW))
			{
				//Just update the frequency
				SearchTreeNode<SpeechWord> * STN = BST_SpeechWords.get(SW);
				STN->contents.updateFequency();
			}
			else
			{
				//add the SW
				BST_SpeechWords.add(SW);
			}
		}
	}//end of file reading loop
	//print the tree
	cout << "Here is the lsit of words president used in his speeches and their frequency." << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	BST_SpeechWords.printInorder(cout);
	cout << endl;
	inWords.close();
	in.close();
	system("pause");

	return 0;
}


/////////////////////////////////////////////////////////////////////
bool Contains(string arr[], string wrd, int length)
{
	convertToLowerCase(wrd);

	for (int i = 0; i < length; i++)
	{
		if (wrd == arr[i])
		{
			return true;
		}
	}

	return false;
}

void convertToLowerCase(string & text)
{
	string temp = "";

	for (size_t i = 0; i < text.length(); i++)
	{
	unsigned	char ch = static_cast<unsigned char>(text[i]);

		if (!ispunct(ch))
		{
			if (isprint(ch))
			{
				if (ch >= 0 && ch <= 255)
				{
					if (isalpha(ch))
					{
						//cout << text[i] << endl;
						temp += static_cast<unsigned char>(tolower((ch)));
					}
				}
			}
		}
	}

	text = temp;
}