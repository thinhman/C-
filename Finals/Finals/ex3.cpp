#include <iostream>
//#include <new>
#include <thread>
#include <string>
#include <future>

using namespace std;
double funcA(double a) {
	if (a < 1)
		throw "less than 1";
	return a*a;
}
int funcB(int b) {
	if (b < 5)
		return b;
	return b * 2;
}
int * funcC() {
	int * t = new int;
	return t;
}
int main4() {
	int iValue, *iPtr;
	double dValue;
	cout << "Enter a number: " << endl;
	cin >> dValue;
	std::future<double> ftr = std::async(funcA, dValue);
	try
	{
		double d = ftr.get();
		cout << d << endl;
	}
	catch (char const *e) {
		std::cout << e << std::endl;
	}
	cout << "Enter an int: " << endl;
	cin >> iValue;
	std::future<int> ftr1 = std::async(funcB, iValue);
	try
	{
		int d = ftr1.get();
		cout << d << endl;
	}
	catch (...) {
		std::cout << "Error " << std::endl;
	}
	std::future<int*> ftr2 = std::async(funcC);
	try
	{
		iPtr = ftr2.get();
		/*cout << (*iPtr) << endl;
		(*iPtr) = 1;
		cout << (*iPtr) << endl;*/
	}
	catch (const bad_alloc& e) {
		std::cout << "Error " << std::endl;
	}
	/*int iValue, *iPtr;
	double dValue;
	cin >> iValue >> dValue;
	try {
		dValue = funcA(dValue);
	}
	catch (const char *s) {
		cout << s << endl;
	}
	cout << dValue << endl;
	iValue = funcB(iValue);
	try {
		iPtr = funcC();
	}
	catch (const bad_alloc& e) {
		cout << "Allocation failed\n";
	}*/
	system("pause");
	return 0;
}