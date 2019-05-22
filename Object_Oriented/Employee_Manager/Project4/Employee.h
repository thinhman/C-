#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<iomanip>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;

class Employee
{
protected:
	string FirstName;
	string LastName;
	const static int  MIN_NUM_NAMES = 2;
public:
	Employee(const string & Fname = "First name is not set", const string & Lname = "Last name not set");
	virtual const string getFirstName() = 0;
	virtual const string getFullName() = 0;
	virtual const string getLastName() = 0;
	virtual void setFirstName(string Fname) = 0;
	virtual void setLastName(string Lname) = 0;
	virtual const string toString() = 0;

}; 
#endif
