#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <iostream>


void theFun(int i, std::promise<int> & p) {
	std::string str("Hello from future!");
	std::cout << str << " i:" << i << std::endl;
	int x = i * 2;
	p.set_value(x);
}

int main1() {

	std::promise<int> prms;
	std::future<int> fut = prms.get_future();
	std::thread th(theFun, 3, std::ref(prms));
	std::cout << "Hello from main!\n";
	std::cout << "Returned from future: " << fut.get() << std::endl;
	th.join();
	system("pause");
	return 0;
}