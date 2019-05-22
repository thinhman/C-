//#include <iostream>
//#include <memory>
//#include <string>
//using namespace std;
//
//class Person {
//private:
//	string m_name;
//public:
//	Person(string name) : m_name(name) { cout << "Person " << name << endl; }
//	Person() : m_name("Nameless") { cout << "Nameless Person created" << endl; }
//	~Person() { cout << "Person is destroyed" << endl; }
//	void speak() { cout << "Person " << m_name << " speaks!" << endl; }
//};
//
//
//void deletePerson(Person *p) { cout << "Custom deleting.\n"; delete[] p; }
//
//int main() {
//
//	Person *p = new Person("Jim"); // raw pointer
//	shared_ptr<Person> sp(p); // ref count = 1
//	shared_ptr<Person> sp2 = sp; // ref count = 2
//	cout << "Reference count sp1: " << sp.use_count() << endl;
//	cout << "Reference count sp2: " << sp2.use_count() << endl;
//	sp.reset(); // sp = nullptr
//	cout << "Reference count sp1: " << sp.use_count() << endl;
//	cout << "Reference count sp2: " << sp2.use_count() << endl;
//	//sp->speak();
//	sp2->speak();
//	//Person *temp = sp2.get();  // dangerous
//
//	shared_ptr<Person> sp3(new Person[3], deletePerson);
//	
//	shared_ptr<Person> sp4 = make_shared<Person>("Sarah");
//	shared_ptr<Person> sp5(new Person("Sarah"));
//
//
//	system("pause");
//	return 0;
//}