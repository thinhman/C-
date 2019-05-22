//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//using namespace std;
//
//void printFacebook(map<string, vector<string>>& m) {
//
//	for (pair<string, vector<string>> p : m) {
//		cout << p.first << endl;
//		for (string f : p.second) {
//			cout << "\t" << f << endl;
//		}
//	}
//}
//
//int main() {
//
//	map<string, vector<string>> facebook;
//
//	facebook["Syndy"].push_back("James");
//	facebook.find("Syndy")->second.push_back("Phuong");
//	//map<string, vector<string>>::iterator f = facebook.find("Syndy");
//	//auto f = facebook.find("Syndy");
//
//	facebook["Germaine"];
//	facebook.find("Germaine")->second.push_back("Agatha");
//	facebook.find("Germaine")->second.push_back("Anges");
//	facebook.find("Germaine")->second.push_back("Jack");
//	facebook["Abby"];
//	facebook.find("Abby")->second.push_back("Thinh");
//	printFacebook(facebook);
//	system("pause");
//}