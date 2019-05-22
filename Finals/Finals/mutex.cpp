////
////  ListRace.cpp
////  multithreading
////
////  Created by Solomon Russell on 4/22/17.
////  Copyright © 2017 Solomon Russell. All rights reserved.
////
//#include <vector>
//#include <thread>
//#include <iostream>
//#include <mutex>
//#include <algorithm>
//using namespace std;
//
//struct List {
//	struct Node {
//		int value;
//		Node* next;
//		Node(int y) : value(y), next(nullptr) { }
//	};
//	std::mutex m;
//	Node * head;
//	List() : head(nullptr) { }
//	void insert(int value) {
//		//std::unique_lock<std::mutex> lock(m);
//		m.lock();
//		auto node = new Node(value);
//		node->next = head;
//		head = node;
//		
//		m.unlock();
//	}
//	int count() const;
//};
//
//void thFun(List &list) {
//	for (int i = 0; i < 100; i++) {
//		
//			list.insert(i);
//		
//	}
//}
//
//
//int main1() {
//
//	List l;
//
//	std::vector<std::thread> workers;
//	for (int i = 0; i < 10; i++) {
//		workers.push_back(std::thread(thFun, std::ref(l)));
//	}
//	std::for_each(workers.begin(), workers.end(), [](std::thread &th) {
//		th.join();
//	});
//	std::cout << "Number of nodes: " << l.count() << std::endl;
//	system("pause");
//	return 0;
//}
//
//int List::count() const {
//	int count = 0;
//	auto p = head;
//	while (p != nullptr) {
//		count++;
//		p = p->next;
//	}
//	return count;
//}
// mutex::lock/unlock

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_thread_id(int id) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	//mtx.lock();
	std::cout << "thread #" << id << '\n';
	//mtx.unlock();
}

int main2()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i<10; ++i)
		threads[i] = std::thread(print_thread_id, i + 1);

	for (auto& th : threads) th.join();
	system("pause");
	return 0;
}