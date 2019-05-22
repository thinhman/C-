//#include <iostream>
//#include <vector>
//using namespace std;
//
//class MyVector {
//	int size;
//	double * arr;
//
//public:
//	MyVector(int i) {
//		arr = new double[i];
//	}
//	MyVector(const MyVector& rhs) {
//		size = rhs.size;
//		arr = new double[size];
//		for (int i = 0; i < size; i++) { arr[i] = rhs.arr[i]; }
//	}
//	MyVector(MyVector&& rhs) {
//		size = rhs.size;
//		arr = rhs.arr;
//		rhs.arr = nullptr;
//	}
//
//	/*
//	* Assignment operator and move assignment operator not shown
//	*/
//
//	~MyVector() { delete[] arr; }
//};
//
//vector<int> returnVector() {
//
//	vector<int> a(200);
//	return a;  // implicitly calls the move constructor of a vector
//}
//
//void foo(MyVector v) { }
//
//MyVector createMyVector() { return MyVector(50); }
//
//int main(int argc, const char * argv[]) {
//
//	MyVector v1(createMyVector());
//
//	// do a whole bunch stuff with v1
//	MyVector v2(std::move(v1));  // I don't need v1 anymore
//								 // I should not access v1 
//								 // I could assign to v1
//
//	return 0;
//}
