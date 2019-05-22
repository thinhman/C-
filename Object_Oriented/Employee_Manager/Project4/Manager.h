#pragma once
#include "Employee.h"
#ifndef MANAGER_H
#define MANAGER_H

class Manager:public Employee
{
protected:
	double salary;
	string TitleOfBoss;
public:
	virtual const string getFirstName();
	virtual const string getFullName();
	virtual const string getLastName();
	virtual void setFirstName(string Fname);
	virtual void setLastName(string Lname);
	virtual const string toString();
	Manager(const string & Fname = "First name is not set", const string & Lname = "Last name is not set", double sal = 0.0, string BTitle = "Boss title not set");
	virtual const string getBossTitle();
	virtual const double getSalary();
	virtual void setBossTitle(string Title);
	virtual void setSalary(double sal);



};

#endif
