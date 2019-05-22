#include <iostream>
#include <string>
using namespace std;


//1) Basic singleton : static function “GetInstance” provides the access point; 
//constructor, copy constructor and operator= are hidden from the user.
//The singleton is allocated upon first demand(lazy initialization).
//Null pointer is used to constrol first access, hence must be initialized in a C++ way – out of the class (as a static member).

//Clarity - the checking of the pointer being null is effectively what the compiler does under the hood when 
//constructing static objects.From a 'learning' perspective, 
//it's instructive to understand what's happening when you use static objects in method scope.
//
//Lazy Allocation - in the first case, the Singleton object is heap - allocated.
//If your function never runs, the object is never constructed and never consumes memory.
//But, in the second case, memory is assigned by the linker to hold the object before the program starts, 
//even though 'construction' is lazy.
class CKeyboard
{
public:
	static CKeyboard* GetInstance()
	{
		if (!m_pInstance)
			m_pInstance = new CKeyboard();
		return m_pInstance;
	}

private:
	CKeyboard() {}
	CKeyboard(const CKeyboard&);
	CKeyboard& operator=(const CKeyboard&);

	static CKeyboard *m_pInstance;
};

CKeyboard* CKeyboard::m_pInstance = NULL;

//2) Meyers singleton : in this implementation, first creation is “delegated” to the compiler, 
//using “static” keyword within function.This way provies well - known creation point for static variable.
//Note, that “GetInstance” access function’s return value is a reference rather then pointer(as in previous example).
//Working with a reference is better : now user can not delete the singleton’s pointer.
//In addition, this implementation is so simple!

//class CKeyboard
//{
//public:
//	static CKeyboard& GetInstance()
//	{
//		static CKeyboard keyboard;
//		return keyboard;
//	}
//
//private:
//	CKeyboard() {}
//	CKeyboard(const CKeyboard&);
//	CKeyboard& operator=(const CKeyboard&);
//};