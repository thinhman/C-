#pragma once
#include "BankAccount.h"
#ifndef BANKACCOUNTLIST_H
#define	BANKACCOUNTLIST_H

class BankAccountList
{
private:
	static const int MAX = 30;
	BankAccount List[MAX];
	int list_state;
	int num_elements;
public:
	BankAccountList();
	void addAccount(const BankAccount & BA);
	bool findAccount(const string & actNum, int & i) const;
	const string toString();
	bool depositMoney(const string & actNum, double money);
	bool withDrawMoney(const string & actNum, double money);
	void makeEmpty();
	void print(ostream & out);
	bool deleteAccount(const string & actNum);
	void sort(int flag);
	bool updateAccount();
	void setLastName(const string  & lname, const string & actNum);
	void setAccountAt(BankAccount & BA, unsigned int index);
	bool getAccountAt(BankAccount & BA, unsigned int & index) const;
	double getBalance(const string & actNum);
	static int getCapacity();
	const string getFirstName(const string & actNum);
	const string getFullName(const string & actNum);
	void getHighestBalanceAccount(BankAccount & BA);
	static void getInstance(BankAccountList & BAL);
	static void getInstance(BankAccountList & BAL, ifstream & in);
	int getNumberOfElements();
	const string getLastName(const string & actNum);
	int getLengthOfLongestFirstName();
	int getListState();
	int getLengthOfLongestLastName();
	/*
	double getMeanOfAllDeposits();
	void getSmallestBalanceAccount(BankAccount & BA);
	bool isEmpty() const;
	bool isFull() const;
	const string listDescription();
	unsigned int numberOfDepositsAboveMean();
	unsigned int numberOfDepositsAtOrBelowMean();
	void printListAsReport();
	void printStatistics(ostream & out);
	double Standard_Deviation_Deposits();
	double sumAllDeposits();
	void writeToNewInputFile(ostream & out);*/
};





#endif
