//#include <iostream>
//#include <exception> // excpetion class c++11
//using namespace std;
//
//class Example {
//public:
//	~Example() {
//		try {
//			// Never, ever have a destructor throw an 
//			// exception
//			//throw 20;
//		}
//		catch (...) { cerr << "exception thrown in destructor"; }
//	}
//};
//
//class DivideByZero : public exception {
//public:
//	DivideByZero(int numerator, char *s)
//		: m_numerator(numerator), exception(s) {
//	}
//	int getNumerator() const { return m_numerator; }
//private:
//	int m_numerator;
//};
//
//int main1() {
//
//	try {
//		Example x;
//		//DivideByZero e;
//		int a = 2, b = 1;
//		if (b == 0)
//			throw DivideByZero(a, "divide by zero");
//		cout << a / b;
//		
//	}
//	catch (DivideByZero e) {
//		cerr << "ERROR: " << e.what() << endl;
//		cerr << "Your numerator is " << e.getNumerator() << endl;
//	}
//	catch (exception e) {
//		cerr << "ERROR: unknown exception" << endl;
//	}
//	catch (int e) {
//		cerr << "ERROR: integer exception thrown: "
//			<< " error #" << e << endl;
//	}
//	catch (...) {  // catches everything, shouldn't use awesome
//		cerr << "ERROR: unexpected exception" << endl;
//	}
//	system("pause");
//}