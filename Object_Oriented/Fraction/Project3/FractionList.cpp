#include "FractionList.h"
FractionList::FractionList() :isSorted(0), num_elements(0)
{
}
void FractionList::addFraction(const Fraction & F)
{
	if (num_elements < MAX)
	{
		List[num_elements] = F;
		num_elements++;
		isSorted = false;
	}
	else
	{
		cout << "List is Full\n";
	}
}
const string FractionList::toString()
{
	ostringstream os;
	
	for (size_t i = 0; i < num_elements; i++)
	{
		os << List[i].toString() << endl;

	}
	return os.str();
}
void FractionList::sort()
{
	for (size_t i = 0; i < num_elements; i++)
	{
		for (size_t j = 0; j < num_elements - i - 1; j++)
		{
			if ((List[j].getTop()*List[j + 1].getBottom()) >(List[j + 1].getTop()*List[j].getBottom()))
			{
				Fraction temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
			isSorted = true;
		}
	}
}
bool FractionList::isFull()
{
	return num_elements == MAX;
}
bool FractionList::isEmpty()
{
	return num_elements == 0;
}
size_t FractionList::getNumberOfElements()const
{
	return num_elements;
}
istream & operator >> (istream & in, FractionList & FL)
{
	while (in.peek() != EOF && FL.getNumberOfElements() < FractionList::MAX)
	{
		Fraction f;
		in >> f;
		FL.addFraction(f);
	}
	cout << "File read successfully.\n";
	return in;
}
ostream & operator << (ostream & out, const FractionList & FL)
{
	for (size_t i = 0; i < FL.getNumberOfElements(); i++)
	{
		out << FL.List[i] << '\n';
	}
	return out;
}
void getInstance(FractionList & FL)
{
	int choice = 1;
	while (choice != 0 && FL.getNumberOfElements() < 30)
	{
		Fraction f;
		cin >> f;
		FL.addFraction(f);
		cout << "\nEnter 1 to add another fraction, or 0 to end: ";
		cin >> choice;
	}
}