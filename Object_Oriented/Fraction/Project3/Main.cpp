#include "FractionList.h"


int main()
{
	FractionList FL;
	cout << "\nEnter full path to file for data entry: ";
	cin.ignore();
	string inputFile;
	getline(cin, inputFile);
	ifstream in(inputFile);
	while (!in.is_open())
	{
		cout << "\nFile could not be openeed, please enter another full path to file for data entry: ";
		cin.ignore();
		getline(cin, inputFile);
		ifstream in(inputFile);
	}

	in >> FL;

	cout << "Enter full path to file to which to output the Fractions:";
	cin.ignore();//Use ignore on Mac
	string outFile;
	getline(cin, outFile);
	ofstream out;
	out.open(outFile);

	while (!out.is_open()) {
		cout << "Failed to create output file. Enter Path:" << endl;
		cin.ignore();
		getline(cin, outFile);
	}
	cout << "The fraction list outputted to console: " << endl;
	cout << FL << endl;
	cout << "Now writing fraction list to an output file." << endl;

	cout << FL << endl;

	in.close();
	out.close();

	system("pause");
	return 0;
}