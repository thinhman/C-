#include "BankAccountList.h"

BankAccountList::BankAccountList()
{
	num_elements = 0;
	list_state = 0;
}
const string BankAccountList::toString()
{
	ostringstream os;
	os << left << setw(26) << left << "Name" << left << setw(20) << "Account Number" << "Balance\n"
		<< "------------------------------------------------------------------------------\n";
	for (size_t i = 0; i < num_elements; i++)
	{
		os << List[i].toString();

	}
	return os.str();
}
bool BankAccountList::findAccount(const string & actNum, int & i) const
{
	bool found;
	int index = -1;
	for (size_t i = 0; i < num_elements; i++)
	{
		if (List[i].getAccountNumber() == actNum)
		{
			found = true;
			index =i;
			break;
		}
		
	}
	
	return found;
}
void BankAccountList::addAccount(const BankAccount & BA)
{
	if (num_elements == MAX)
	{
		cout << "List is Full\n";
	}
	int index = -1;
	if (findAccount(BA.getAccountNumber(), index))
	{
		cout << "Account with " << BA.getAccountNumber() << " is already in the list" << endl;
	}
	else
	{
		List[num_elements] = BA;
		num_elements++;
		list_state = 0;
	}
}
bool BankAccountList::depositMoney(const string & actNum, double money)
{
	bool deposit = false;
	int index;
	if (findAccount(actNum, index))
	{
		List[index].deposit(money);
		cout << "Deposit successful\n";
		deposit = true;
		if (list_state == 3)
		{
			list_state = 0;
		}
	}
	else
	{
		cout << "Bank Account was not found\n";
	}
	return deposit;
}
bool BankAccountList::withDrawMoney(const string & actNum, double money)
{
	bool withdraw = false;
	int index;
	if (findAccount(actNum, index))
	{
		List[index].withdraw(money);
		cout << "Deposit successful\n";
		withdraw = true;
		if (list_state == 3)
		{
			list_state = 0;
		}
	}
	else
	{
		cout << "Bank Account was not found\n";
	}
	return withdraw;
}
void BankAccountList::makeEmpty()
{
	num_elements = 0;
	list_state = 0;
}
void BankAccountList::print(ostream & out)
{
	out << toString();
}
bool BankAccountList::deleteAccount(const string & actNum)
{
	bool del = false;
	int index;
	if (findAccount(actNum, index))
	{
		List[index] = List[num_elements - 1];
		num_elements--;
		if (list_state != 0)
		{
			sort(list_state);
		}
		cout << "\nAccount deleted successfully.\n";
		del = true;
	}
	else
	{
		cout << "No Account\n";
	}
	return del;
}
void BankAccountList::sort(int flag)
{
	for (size_t i = 0; i < num_elements; i++)
	{
		for (size_t j = 0; j < num_elements - i - 1; j++)
		{
			if (flag == 1)
			{
				if (List[j].getAccountNumber() > List[j + 1].getAccountNumber())
				{
					BankAccount temp = List[j];
					List[j] = List[j + 1];
					List[j + 1] = temp;
				}
				list_state = 1;
			}

			if (flag == 2)
			{

				if (List[j].getLastName() > List[j + 1].getLastName())
				{
					BankAccount temp = List[j];
					List[j] = List[j + 1];
					List[j + 1] = temp;
				}
				list_state = 2;
			}

			if (flag == 3)
			{
				if (List[j].getBalance() > List[j + 1].getBalance())
				{
					BankAccount temp = List[j];
					List[j] = List[j + 1];
					List[j + 1] = temp;
				}
				list_state = 3;
			}
		}
	}
}
bool BankAccountList::updateAccount()
{
	bool update = false;
	string num;
	int index;
	string last;
	cout << "Please enter your account number: ";
	cin.sync();
	cin >> num;
	if (findAccount(num, index))
	{
		cout << "\nAccount found\n";
		cout << "Enter your new Last Name: ";
		cin >> last;
		for (auto & dummy : last)
		{
			dummy = toupper(dummy);
		}
		List[index].setLastName(last);
		cout << "\nLast name changed successfully.\n";
		update = true;
		if (list_state == 2)
		{
			list_state = 0;
		}
	}
	else
	{
		cout << "No Account\n";
	}
	return update;
}
void BankAccountList::setLastName(const string  & lname, const string & actNum)
{
	int index;
	if (findAccount(actNum, index))
	{
		List[index].setLastName(lname);
		cout << "Last name updated successfully\n";
		if (list_state == 2)
		{
			list_state = 0;
		}
	}
	else
	{
		cout << "No Account\n";
	}
}
void BankAccountList::setAccountAt(BankAccount & BA, unsigned int index)
{
	if (index >= num_elements)
	{
		cout << "The bank account list does not contain an index of " << index << endl;
		return;
	}
	else
	{
		BA = List[index];

	}
}
bool BankAccountList::getAccountAt(BankAccount & BA, unsigned int & index) const
{
	bool getAct = false;
	if (index < num_elements)
	{
		BA = List[index];
		getAct = true;
	}
	else
	{
		cout << "No changes made \n";
	}
	return getAct;
}
double BankAccountList::getBalance(const string & actNum)
{
	int index;
	double bal = -1;
	try
	{
		if (findAccount(actNum, index))
		{
			bal = List[index].getBalance();
		}
		else
		{
			throw string("No Account\n");
		}

	}
	catch(string message)
	{
		cout << message;
	}
	
	return bal;
}
int BankAccountList::getCapacity()
{
	return MAX;
}
const string BankAccountList::getFirstName(const string & actNum)
{
	int index;
	string first;
	try
	{
		if (findAccount(actNum, index))
		{
			first = List[index].getFirstName();
		}
		else
		{
			throw string("No Account\n");
		}

	}
	catch (string message)
	{
		cout << message;
	}

	return first;
}
const string BankAccountList::getFullName(const string & actNum)
{
	int index;
	string fullname;
	try
	{
		if (findAccount(actNum, index))
		{
			fullname = List[index].getFullName;
		}
		else
		{
			throw string("No Account\n");
		}
	}
	catch (string message)
	{
		cout << message;
	}
	return fullname;
}
void BankAccountList::getHighestBalanceAccount(BankAccount & BA)
{
	if (num_elements == 0)
	{
		cout << "The list is empty\n";
	}
	else
	{
		for (size_t i = 0; i < num_elements; i++)
		{
			if (static_cast<int>(BA.getBalance() * 100) < static_cast<int>(List[i].getBalance() * 100))
			{
				BA = List[i];
			}
		}
	}
}
void BankAccountList::getInstance(BankAccountList & BAL)
{
	size_t redo;
	BankAccount BA;
	do
	{
		BankAccount::getInstance(BA);
		BAL.addAccount(BA);
		cout << "Enter 1 to add another account or 0 to finish: ";
		cin >> redo;
		cout << endl;
	} while (redo != 0);
}
void BankAccountList::getInstance(BankAccountList & BAL, ifstream & in)
{
	BankAccount BA;
	while (in.peek() != EOF && BAL.getNumberOfElements() < MAX)
	{
		BankAccount::getInstance(BA, in);
		BAL.addAccount(BA);
	}
	cout << "File read successfully.\n";
	if (in.peek() != EOF)
	{
		cout << "File had more accounts than the max amount the list could hold.\n";
	}
}
int BankAccountList::getNumberOfElements()
{
	return num_elements;
}
const string BankAccountList::getLastName(const string & actNum)
{
	int index;
	string last;
	try
	{
		if (findAccount(actNum, index))
		{
			last = List[index].getLastName();
		}
		else
		{
			throw string("No Account\n");
		}

	}
	catch (string message)
	{
		cout << message;
	}

	return last;
}
int BankAccountList::getListState()
{
	return list_state;
}
int BankAccountList::getLengthOfLongestFirstName()
{
	string First = "";
	int length;
	for (size_t i = 0; i < num_elements; i++)
	{
		if (First.length() < List[i].getFirstName().length())
		{
			First = List[i].getFirstName();
		}
	}
	length = First.length();
	return length;
}
int BankAccountList::getLengthOfLongestLastName()
{
	string Last = "";
	int length;
	for (size_t i = 0; i < num_elements; i++)
	{
		if (Last.length() < List[i].getLastName().length())
		{
			Last = List[i].getLastName();
		}
	}
	length = Last.length();
	return length;
}
