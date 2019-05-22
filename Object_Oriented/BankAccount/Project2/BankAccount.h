#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

class BankAccount
{
private:
	string ActNum, FirstName, LastName;
	double balance;

public:
	BankAccount(const string actNm = "Account number not set", const string fname = "First name not set", const string lname = "Last name not set", double bal = 0);

	void deposit(double money);
	const string getAccountNumber()const;
	const double getBalance();
	const string getFirstName();
	const string getFullName();
	const string getLastName();
	void setAccountNumber(string actNm);
	void setLastName(string lNm);
	const string toString();
	void withdraw(double money);
	void print(ostream & cout);
	static void getInstance(BankAccount & BA);
	static void getInstance(BankAccount & BA, ifstream & in);


};

#endif