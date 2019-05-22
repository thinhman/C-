#include "MainQueue.h"
#include <string>
using namespace std;

void testInt();
void testChar();
void testFloat();
void testString();

int main()
{

	testInt();
	testChar();
	testFloat();
	testString();

	return 0;
}

void testInt()
{
	Queue<int> Int_ArrayQueue;
	cout<<"The capcity of queue is "<<  Int_ArrayQueue.getCapacity()<<endl;
	cout<<"We will enqueue some integers on the queue now.\n";
	bool done = false;
	int val = int();
	while(!done)
	{
		cout<<"Please enter an integer to be enqueued : ";
		cin>>val;
		
		Int_ArrayQueue.enqueue(val);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the integers in the Queue.\n";

	while(!Int_ArrayQueue.isEmpty())
	{
		cout<<Int_ArrayQueue.dequeue()<<"  ";
	}
//	Int_ArrayQueue.dequeue();//change MAX  to 5 and uncomment.
	cout<<endl;
}
//---------------------------------------------------------------
void testChar()
{
	Queue<char> Char_ArrayQueue;
	cout<<"We will enqueue some characters in the Queue now.\n";
	bool done = false;
	char val = char();
	while(!done)
	{
		cout<<"Please enter an character to be put in the Queue : ";
		cin>>val;
		
		Char_ArrayQueue.enqueue(val);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the characters in the Queue.\n";

	while(!Char_ArrayQueue.isEmpty())
	{
		cout<<Char_ArrayQueue.dequeue()<<"  ";
	}
	cout<<endl;
}
//-------------------------------------------------------------
void testFloat()
{
	Queue<double> Float_ArrayQueue;
	cout<<"We will enqueue some floating point numbers in the Queue now.\n";
	bool done = false;
	float val = float();
	while(!done)
	{
		cout<<"Please enter a floating point number to be added to the Queue : ";
		cin>>val;
		
		Float_ArrayQueue.enqueue(val);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the floating point numbers  in the Queue.\n";

	while(!Float_ArrayQueue.isEmpty())
	{
		cout<<Float_ArrayQueue.dequeue()<<"  ";
	}
	cout<<endl;
}
//-------------------------------------------------------------
void testString()
{
	Queue<string> string_ArrayQueue;
	cout<<"We will enqueue some strings in the Queue now.\n";
	bool done = false;
	string val = string();
	while(!done)
	{
		cout<<"Please enter an string to be added to the Queue : ";
		cin>>val;
		
		string_ArrayQueue.enqueue(val);
		cout<<"More data? Enter 0 to continue and 1 to exit: ";
		cin>>done;
	}

	cout<<"Now printing the strings in Queue.\n";

	while(!string_ArrayQueue.isEmpty())
	{
		cout<<string_ArrayQueue.dequeue()<<"  ";
	}
	cout<<endl;
}
//---------------------------------------------------------------

