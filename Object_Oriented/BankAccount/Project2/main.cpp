#include "BankAccountList.h"
int main()
{
	BankAccountList A;
	BankAccount BA;
	int i;
	double money;
	BA.getInstance(BA);
	A.addAccount(BA);
	/*A.print(cout);
	cout << "deposit: ";
	cin >> money;
	A.depositMoney(BA.getAccountNumber(), money);
	A.print(cout);
	cout << "Withdraw: ";
	cin >> money;
	A.withDrawMoney(BA.getAccountNumber(), money);
	A.print(cout);*/
	system("pause");
	return 0;
}