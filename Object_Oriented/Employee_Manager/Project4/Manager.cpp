#include "Manager.h"
const string Manager::getFirstName()
{
	return FirstName;
}
const string Manager::getFullName()
{
	string FullName = FirstName + " " + LastName;
	return FullName;
}
const string Manager::getLastName()
{
	return LastName;
}
void Manager::setFirstName(string Fname)
{
	FirstName = Fname;

}
void Manager::setLastName(string Lname)
{
	LastName = Lname;
}
const string Manager::toString()
{
	ostringstream os;
	os << setprecision(2) << fixed << showpoint
		<< "Manager Info:\n"
		<< "Name: " << getFullName()
		<< "\nBoss's Title: " << TitleOfBoss
		<< "\nSalary: $" << salary
		<< "\n---------------------------------\n";
	return os.str();
}
Manager::Manager(const string & Fname, const string & Lname, double sal, string BTitle) : Employee(Fname, Lname), salary(abs(sal)), TitleOfBoss(BTitle)
{
	if (BTitle.length() < MIN_NUM_NAMES)
	{
		cout << "Title of boss needs to be more than 2 character, title not set\n";
		TitleOfBoss = "Boss title not set";
	}

}
const string Manager::getBossTitle()
{
	return TitleOfBoss;
}
const double Manager::getSalary()
{
	return salary;
}
void Manager::setBossTitle(string Title)
{
	TitleOfBoss = Title;
}
void Manager::setSalary(double sal)
{
	salary = sal;
}