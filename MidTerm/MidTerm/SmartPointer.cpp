#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Dynamic {
public:
	Dynamic() : m_ip(nullptr), m_numRef(nullptr) {

	}
	Dynamic(T *p) : m_ip(p), m_numRef(new int(1)) {
		cout << "Dnymaic one argument ctor" << endl;
	}
	Dynamic(const Dynamic& rhs) {
		cout << "Dnymaic copy constructor" << endl;
		m_ip = rhs.m_ip;
		m_numRef = rhs.m_numRef;
		(*m_numRef)++;
	}

	const Dynamic& operator=(const Dynamic &rhs) {

		if (m_numRef == nullptr) {
			m_ip = rhs.m_ip;
			m_numRef = rhs.m_numRef;
			(*m_numRef)++;
		}
		else if (m_numRef == rhs.m_numRef)
			return *this;
		else if (*m_numRef > 1) {
			--(*m_numRef);
			m_numRef = rhs.m_numRef;
			m_ip = rhs.m_ip;
			++(*m_numRef);
		}
		else {
			delete m_ip;
			delete m_numRef;
			m_ip = rhs.m_ip;
			m_numRef = rhs.m_numRef;
			++(*m_numRef);
		}
		return *this;
	}

	void set(T c) { // equivalent of *p = ?
					// check to see if it's valid
		*m_ip = c;
	}

	T get() const { // equivalent of *p
		return *m_ip;
	}

	int use_count() const {
		// check to see if it's valid
		return *m_numRef;
	}

	~Dynamic() {
		cout << "Reference count: " << use_count() << endl;
		if (*m_numRef > 1) {
			cout << "Dynamic ref decremented now!" << endl;
			--(*m_numRef);
		}
		else {
			cout << "Dynamic deleted!" << endl;
			delete m_ip;
			delete m_numRef;
		}
	}
private:
	T *m_ip;
	int *m_numRef;
};


int main() {

	
	{
		Dynamic<int> d(new int(42));
		Dynamic<int> f = d;
		Dynamic<int> e;
		e = d;
	}
	system("pause");
	return 0;


}