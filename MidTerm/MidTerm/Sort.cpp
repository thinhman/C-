//#include <algorithm>
//#include <string>
//#include <iostream>
//#include <list>
//#include <vector>
//using namespace std;
//
//void foo(string name) {
//	cout << "my name is " << name << endl;
//}
//
//struct Person {
//	string name;
//	int idNum;
//	Person() { }
//	Person(string n, int id) : name(n), idNum(id) { }
//};
//bool compare(const Person& x, const Person& y) {
//	return x.idNum < y.idNum;
//}
//bool operator<(const Person& x, const Person& y) {
//	return x.idNum < y.idNum;
//}
//
//bool sortbyName(const Person& x, const Person& y) {
//	return x.name < y.name;
//}
//
//int main() {
//
//	///void(*p)(string);   // function pointer
//	//p = foo;            // or p = &foo
//	//p(s);               // or (*p)(s);
//
//	list<Person> vi;
//	Person a;
//	a.name = "Zack";
//	a.idNum = 9;
//	vi.push_back(a);
//	Person b;
//	b.name = "Alice";
//	b.idNum = 2;
//	vi.push_back(b);
//	vi.emplace_back(Person("Jay", 45)); // c++14
//	vi.sort(compare);
//	//sort(vi.begin(), vi.end()); // sorts by idNum
//	//sort(vi.begin(), vi.end(), sortbyName);
//	// using a lambda expression below
//	/*sort(vi.begin(), vi.end(), [](const Person& x, const Person& y) {
//		return x.name < y.name;
//	});*/
//	for (Person k : vi) {
//		cout << k.name << " ";
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <list>
//#include <string>
//#include <cctype>
//
//// comparison, not case sensitive.
//bool compare_nocase(const std::string& first, const std::string& second)
//{
//	unsigned int i = 0;
//	while ((i<first.length()) && (i<second.length()))
//	{
//		if (tolower(first[i])<tolower(second[i])) return true;
//		else if (tolower(first[i])>tolower(second[i])) return false;
//		++i;
//	}
//	return (first.length() < second.length());
//}
//
//int main()
//{
//	std::list<std::string> mylist;
//	std::list<std::string>::iterator it;
//	mylist.push_back("one");
//	mylist.push_back("two");
//	mylist.push_back("Three");
//
//	mylist.sort();
//
//	std::cout << "mylist contains:";
//	for (it = mylist.begin(); it != mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	mylist.sort(compare_nocase);
//
//	std::cout << "mylist contains:";
//	for (it = mylist.begin(); it != mylist.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//	system("pause");
//	return 0;
//}