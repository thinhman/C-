#include "Employee.h"
Employee::Employee(const string & Fname, const string & Lname) : FirstName(Fname), LastName(Lname)
{
	if (Fname.length() < MIN_NUM_NAMES)
	{
		cout << "First Name must be at least 2 character, name is not set. \n";
		FirstName = "First name is not set";
	}
	if (Lname.length() < MIN_NUM_NAMES)
	{
		cout << "Last Name must be at least 2 character, name is not set. \n";
		LastName = "Last name is not set";
	}
}
