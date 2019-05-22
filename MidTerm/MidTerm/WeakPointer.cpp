//#include <string>
//#include <iostream>
//#include <memory>
//using namespace std;
//
//class Student {
//private:
//	string m_name;
//	weak_ptr<Student> m_pFriend;
//public:
//	//Student(const Student&) = default;
//	Student(string name) : m_name(name) { cout << "Student " << name << endl; }
//	Student() : m_name("Nameless") { cout << "Nameless Student created" << endl; }
//	~Student() { cout << "Student is destroyed" << endl; }
//	void makeFriend(shared_ptr<Student> f) { m_pFriend = f; }
//	void speak() { cout << "Student " << m_name << " speaks!" << endl; }
//};
//
//int main() {
//
//	shared_ptr<Student> pS(new Student("Cindy"));
//	shared_ptr<Student> pS2(new Student("Roku"));
//
//	pS->makeFriend(pS2);
//	pS2->makeFriend(pS);
//
//	weak_ptr<Student> wpS = pS;
//
//	cout << "weak pointer reference count" << wpS.use_count() << endl;
//	{
//		shared_ptr<Student> temp = wpS.lock(); // lock returns a shared pointer
//		temp->speak();
//		cout << "weak pointer reference count" << wpS.use_count() << endl;
//	}
//	cout << "weak pointer reference count" << wpS.use_count() << endl;
//	system("pause");
//}