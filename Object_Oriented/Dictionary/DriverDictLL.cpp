#include "DictionaryLinkedList.h"

void buildFromKeyboardAndPrint()
{
	DictionaryLinkedList DL;
	DictionaryLinkedList::getInstance(cin, DL);
	cout << "Printing your dictionary now: " << endl;
	cout << DL;
}

void buildFromFileAndPrint(DictionaryLinkedList & DL)
{
	cout << "Enter the input file full path: ";
	string fileName;
	cin.sync();
	getline(cin, fileName);
	ifstream in(fileName);

	if (!in.is_open())
	{
		cout << "File opening error. " << endl;
		exit(0);
	}

	DictionaryLinkedList::getInstance(in, DL);
	cout << "Printing your dictionary now: " << endl;
	cout << DL;
}

void searchWord( DictionaryLinkedList & DL)
{
	bool done = false;
	while (!done)
	{
		cout << "Enter the word to be searched in the dictionary: ";
		string wrd;
		cin >> wrd;
		DictionaryNode DN;
		bool isThere = DL.contains(wrd, DN);
		if (isThere){
			cout << "The word is in dictionary. Details are below:" << endl;
			cout << DN << endl;
		}
		else{
			cout << "The word " << wrd << " is not yet added to dictionary." << endl;
		}
		cout << "More word searches? Enter 0 to continue or 1 to exit: ";
		cin >> done;
	}
}
int main()
{
	{
		//buildFromKeyboardAndPrint();
		DictionaryLinkedList DL;
		buildFromFileAndPrint(DL);
		searchWord(DL);
		return 0;
	}
	
}
/*
Enter the word to be added to the dictionary: Zoo
Enter the meaning of the word: A place for animals to live
More words? Enter 0 to continue or 1 to exit: 0
Enter the word to be added to the dictionary: DAY
Enter the meaning of the word: Part of time when sun has risen
More words? Enter 0 to continue or 1 to exit: 0
Enter the word to be added to the dictionary: Apple
Enter the meaning of the word: A fruit of red and other colors and ellipsiodal shape
More words? Enter 0 to continue or 1 to exit: 0
Enter the word to be added to the dictionary: close
Enter the meaning of the word: Hide something and disappear from view
More words? Enter 0 to continue or 1 to exit: 0
Enter the word to be added to the dictionary: Open
Enter the meaning of the word: display or showing the contents
More words? Enter 0 to continue or 1 to exit: 0
Enter the word to be added to the dictionary: close
Enter the meaning of the word: xyz
The word CLOSE is already in the dictionary.
More words? Enter 0 to continue or 1 to exit: 0
Enter the word to be added to the dictionary: maze
Enter the meaning of the word: zig zag path
More words? Enter 0 to continue or 1 to exit: 1
Printing your dictionary now:
Word: APPLE
Means: A fruit of red and other colors and ellipsiodal shape
Word: CLOSE
Means: Hide something and disappear from view
Word: DAY
Means: Part of time when sun has risen
Word: MAZE
Means: zig zag path
Word: OPEN
Means: display or showing the contents
Word: ZOO
Means: A place for animals to live
From destructor.
*/