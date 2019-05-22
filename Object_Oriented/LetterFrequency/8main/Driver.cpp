#include "LetterFrequencyList.h"

int main()
{
	
	{
		LetterFrequencyList L1;
		string input;
		cout << "Enter text file location: ";
		getline(cin, input);
		ifstream in;
		in.open(input);
		while (!in.is_open())
		{
			cout << "\nFile could not be opened, please enter another text file: " << endl;
			cin.sync();
			getline(cin, input);
			in.open(input);
		}

		while (in.peek() != EOF)
		{
			char nextChar;
			in >> nextChar;
			if (isalpha(nextChar))
			{
				L1.insertInOrder(nextChar);
			}
		}

		cout << L1.toString();

	}
	system("pause");
	return 0;
}