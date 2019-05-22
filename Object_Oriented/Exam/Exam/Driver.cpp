//Thinh Nguyen Final Exam
#include "CharacterFrequency.h"
#include "Iterator.h"
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
//void convertToUpperCase(string & text, BinarySearchTree<CharacterFrequency> & bst);
bool Contains(string arr[], string wrd, int length);
void buildTree(ifstream & in, BinarySearchTree<CharacterFrequency> & bst);
int main()
{
	BinarySearchTree<CharacterFrequency> tree;
	size_t choice;
	cout << "\nEnter full path to inputfile for data entry: ";
	cin.sync();
	string inputFile;
	getline(cin, inputFile);
	ifstream in(inputFile);
	while (!in.is_open())
	{
		cout << "\nFile could not be openeed, please enter another full path to file for data entry: ";
		cin.sync();
		getline(cin, inputFile);
		ifstream in(inputFile);
	}

	cout << "\nEnter full outputpath to file for data entry: ";
	cin.sync();
	string outputFile;
	getline(cin, outputFile);
	ofstream out(outputFile);
	while (!out.is_open())
	{
		cout << "\nFile could not be openeed, please enter another full path to file for data entry: ";
		cin.sync();
		getline(cin, outputFile);
		ifstream out(outputFile);
	}
	buildTree(in, tree);
	
	do
	{
		cout << "\n1. Print search words found and their frequency." << endl
			<< "2. Print search words found and their frequency to output file" << endl
			<< "Enter menu choice or enter 0 to exit: ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			tree.printInorder(cout);
		}
		else if (choice == 2)
		{
			tree.printInorder(out);
		}

	} while (choice != 0);

	in.close();
	out.close();
	return 0;
}

void buildTree(ifstream & in, BinarySearchTree<CharacterFrequency> & bst)
{
	while (in.peek() != EOF)
	{
		char Token;
		string line;
		getline(in, line);
		istringstream is(line);
		while (is.peek() != EOF)
		{

			is >> Token;
			toupper(Token);
			CharacterFrequency charfreq(Token);

			if (isalpha(Token))
			{
				if (!bst.contains(charfreq))
				{
					bst.add(charfreq);
				}
				else
				{
					SearchTreeNode<CharacterFrequency> * ptr = bst.get(charfreq);
					ptr->contents.updateFequency();
				}
			}
		}
	}
	
	//while (in.peek() != EOF)
	//{
	//	char newletter;
	//	string nextString;
	//	if (getline(in, nextString))
	//	{
	//		convertToUpperCase(nextString, bst);
	//	}
	//
	//}
}