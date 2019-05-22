//Thinh Nguyen Assignment 10

#include "WordList.h"
#include "Iterator.h"

void buildTree(ifstream & in, BinarySearchTree<WordList> & B);
void convertToLower(string & token);
void add(string & S, int & L, BinarySearchTree<WordList> & B);
void searchWordListTree(BinarySearchTree<WordList> B);
void printWordListTree(ostream & out, BinarySearchTree<WordList> B);



int main()
{

	BinarySearchTree<WordList> List;
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
	buildTree(in, List);
	
	size_t num;
	do
	{
		cout << "\nEnter menu choice: "
			<< "\n[0] To exit " <<endl
			<< "[1] Print binary search tree in order to the console" << endl
			<< "[2] Search for a word in the tree and have its line numbers printed" << endl
			<< "[3] Print binary search tree in order to the output file" << endl;
			
		cin >> num;
		cout << endl;
		if (num == 1)
		{
			List.printInorder(cout);
		}
		else if (num == 2)
		{
			searchWordListTree(List);

		}
		else if (num == 3)
		{
			cout << "\nPrinted to file\n";
			printWordListTree(out, List);
		}

	} while (num != 0);

	in.close();
	out.close();

	return 0;
}



void convertToLower(string & token)
{
	for (size_t i = 0; i < token.length(); i++)
	{
		token[i] = tolower(token[i]);
	}
}
void buildTree(ifstream & in, BinarySearchTree<WordList> & B)
{
	int line = 0;
	string NextWord;
	while (in.peek() != EOF)
	{
		if (getline(in, NextWord))
		{
			line++;
			add(NextWord, line, B);
		}

	}


}
void add(string & S, int & L, BinarySearchTree<WordList> & B)
{
	size_t i = 0;
	while (i < S.length())
	{
		WordList List;
		string newWord = "";
		if (isalpha(S[i]))
		{

			while (S[i] != ' ' && isalpha(S[i]) || S[i] == '\'')
			{
				newWord += S[i];
				i++;
			}

			if (newWord.length() >= 2)
			{
				convertToLower(newWord);
				List.setWord(newWord);

				if (B.contains(List))
				{
					SearchTreeNode<WordList> * existingWord = B.get(List);
					existingWord->contents.addToList(L);
				}

				else
				{
					List.addToList(L);
					B.add(List);
				}
			}
		}
		else
		{
			i++;
		}
	}
}

void searchWordListTree(BinarySearchTree<WordList> B)
{
	string word;
	cout << "Enter word to be searched: ";
	cin.sync();
	cin >> word;
	WordList w;
	w.setWord(word);
	if (B.contains(w))
	{
		SearchTreeNode<WordList> *w2 = B.get(w);
		cout << '\n' << w2->contents;

	}
	else
	{
		cout << '\n' << word << " is not on the list." << endl;
	}
}

void printWordListTree(ostream & out, BinarySearchTree<WordList> B)
{
	B.printInorder(out);
}