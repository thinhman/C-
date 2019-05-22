//#include <iostream>
//#include <string>
//#include <thread>
//#include <future>
//
//std::string theFun() {
//	std::string str("Hello from future!");
//	throw(std::logic_error("Exception from task!"));
//	return (str);
//}
//
//int main() {
//
//	std::future<std::string> ftr = std::async(theFun);
//	std::cout << "Hello from main!\n";
//	try {
//		std::string str = ftr.get();
//		std::cout << str;
//	}
//	catch (std::exception & e) {
//		std::cout << e.what() << std::endl;
//	}
//	system("pause");
//	return 0;
//}