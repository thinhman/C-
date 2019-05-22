#include "Manager.h"


int main()
{
	size_t num;
	bool flag = false;
	Manager M;
	cout << "Main Menu\n"
		<< "--------------------------------\n";
	do
	{
		
		cout<< "1. Create Manager instance from keyboard:\n"
			<< "2. Print Manager to Console.\n"
			<< "3. Change Manager's last name.\n"
			<< "4. Change Manager's Salary.\n"
			<< "5. Change Manager's Boss's Title."
			<< "6. Print only Manager's name and Salary to console.\n"
			<< "7. Print only Manager's boss's title to console.\n"
			<< "8. Exit\n"
			<< "Pick a number: ";
	
		cin >> num;

		if (num == 1)
		{
			string fname, lname, btitle;
			double sal;
			cout << "\nEnter first name: ";
			cin >> fname;
			cout << "\nEnter last name: ";
			cin >> lname;
			cout << "\nEnter Boss's title: ";
			cin >> btitle;
			cout << "\nEnter salary: ";
			cin >> sal;
			M = Manager(fname, lname, sal, btitle);
			flag = true;
		}

		if (flag)
		{
			if (num == 2)
			{
				cout << M.toString();
			}

			else if (num == 3)
			{
				string newlast;
				cout << "\nEnter new last name: ";
				cin >> newlast;
				M.setLastName(newlast);
			}

			else if (num == 4)
			{
				double newsal;
				cout << "\nEnter new salary: ";
				cin >> newsal;
				M.setSalary(newsal);
			}

			else if (num == 5)
			{
				string newtitle;
				cout << "\nEnter new Boss title: ";
				cin >> newtitle;
				M.setBossTitle(newtitle);

			}

			else if (num == 6)
			{
				cout << "\nFull name: " << M.getFullName()
					<< "\nSalary: $" << M.getSalary();
			}

			else if (num == 7)
			{
				cout << "\nBoss's title: " << M.getBossTitle();
			}
		}

		else
		{
			cout << "\nPlease choose option 1 first to create an instance of manager class.";
		}


	} while (num != 8);

	return 0;
}