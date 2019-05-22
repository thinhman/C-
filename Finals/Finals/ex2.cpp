#include <iostream>
#include <thread>
using namespace std;
void funcA() {
	for (int i = 0; i < 4; i++)
		cout << i;
}
int main3() {
	thread th1(funcA);
	thread th2(funcA);
	th1.join();
	th2.join();
	system("pause");
	return 0;
}