#include "BankAccount.h"

BankAccount::BankAccount(string actNm, string fname, string lname, double bal) : ActNum(actNm), FirstName(fname), LastName(lname)
{
	if (bal < 0)
	{
		cout << "Balance cannot be negative, set to $0.00";
	}
	else
	{
		balance = bal;
	}
}

void BankAccount::deposit(double money)
{
	if (money < 0)
	{
		cout << "Deposit must be greater than $0.00. No money deposited.";
	}
	else
	{
		balance += money;
	}
}

const string BankAccount::getAccountNumber()const
{
	return ActNum;
}

const double BankAccount::getBalance()
{
	return balance;
}

const string BankAccount::getFirstName()
{
	return FirstName;
}

const string BankAccount::getFullName()
{
	string FullName = FirstName + " " + LastName;
	return FullName;
}

const string BankAccount::getLastName()
{
	return LastName;
}

void BankAccount::setAccountNumber(string actNm)
{
	ActNum = actNm;
}

void BankAccount::setLastName(string lNm)
{
	LastName = lNm;
}

const string BankAccount::toString()
{
	ostringstream os;
	os << fixed << showpoint << setprecision(2)
		<< left << setw(13) << FirstName << left << setw(13) << LastName
		<< left << setw(20) << ActNum << "$" << left << setw(9) << balance << '\n';
	return os.str();
}

void BankAccount::withdraw(double money)
{
	if (money > balance)
	{
		cout << "Withdrawal amount cannot exceed current balance. No action taken.";
	}
	balance -= money;
}

void BankAccount::print(ostream & out)
{
	if (&out == &cout)
	{
		cout << toString();
	}

	else if (&out == &out)
	{

		out << toString();
	}
}
void BankAccount::getInstance(BankAccount & BA)
{
	string FirstName, LastName, ActNum;
	double balance;

	cout << "\nEnter first name: ";
	cin >> FirstName;
	cout << "Enter last name: ";
	cin >> LastName;
	cout << "Enter Account number: ";
	cin >> ActNum;
	cout << "Enter balance: ";
	cin >> balance;

	BA = BankAccount(ActNum, FirstName, LastName, balance);
}

void BankAccount::getInstance(BankAccount & BA, ifstream & in)
{
	string FirstName, LastName, ActNum;
	double balance;

	in >> ActNum >> LastName >> FirstName >> balance;
	for (auto & dummy : FirstName)
	{
		dummy = toupper(dummy);
	}

	for (auto & dummy : LastName)
	{
		dummy = toupper(dummy);
	}
	BA = BankAccount(ActNum, FirstName, LastName, balance);
}