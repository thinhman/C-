//#include <iostream>
//#include <memory>
//using namespace std;
//
//class Person {
//public:
//	Person() { cout << "Person Created" << endl; }
//	void speak() { cout << "Person Speaks" << endl; }
//	~Person() { cout << "Person Destroyed" << endl; }
//};
//
//void deleteP(Person *p);
//
//int main() {
//
//	unique_ptr<Person> uP1(new Person()); // lightweight pointer
//	unique_ptr<Person> uP2(new Person());
//
//	uP1 = std::move(uP2);
//
//	//Person *temp = uP1.release(); // releases raw pointer
//	//if (uP1 == nullptr)
//	//	cout << "uP1 emptly" << endl;
//
//	//uP1.reset(new Person()); //
//	//uP2->speak();
//
//	// Can create a unique ptr to an array
//	{
//		unique_ptr<Person[]> people(new Person[3]);
//
//		// With shared ptr have to specify func to deallocate
//		shared_ptr<Person> p2(new Person[3], deleteP);
//	}
//	
//	system("pause");
//}
//
//void deleteP(Person *p) {
//	delete[] p;
//}
//#include <iostream>
//
//
//class UniquePtr {
//private:
//	int *p;
//
//public:
//	// copy ctor
//	UniquePtr() { p = nullptr; }
//	UniquePtr(const UniquePtr& rhs) = delete;
//	UniquePtr(UniquePtr&& rhs) {
//		p = rhs.p;
//		rhs.p = nullptr;
//	}
//	~UniquePtr() { delete p; }
//	// assignment operators
//	UniquePtr& operator=(const UniquePtr& rhs) = delete;
//	UniquePtr& operator=(UniquePtr&& rhs) {
//		delete p;
//		p = rhs.p;
//		rhs.p = nullptr;
//		return *this;
//	}
//};
//
//int main() {
//
//	UniquePtr a, b;
//	// UniquePtr c(a);  // Error! copy ctor is deleted
//
//	// a = b;           // Error! assignment opertor is deleted
//	a = std::move(b);
//}