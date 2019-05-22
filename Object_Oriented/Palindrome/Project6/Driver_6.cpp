#include "StringQueue.h"
#include "Stack.h"
#include <algorithm>

int main()
{

	int num = 0;
	cout << "Palindrome Testing Program\n" << endl;
	cout << "How many strings are to be tested? ";
	cin >> num;
	if (num < 0)
	{
		cout << "Cannot be less than 1\n";
		cout << "Please enter another number\n";
		cin >> num;
	}
	bool palindrome;
	while (num != 0 )
	{
		palindrome = true;
		StringQueue q;
		Stack s;
		string input;
		cout << "Enter your expression\n";
		cin.sync();
		getline(cin, input);
		for (char c : input)
		{
			if (isalpha(c))
			{
				c = toupper(c);
				q.enqueue(c);
				s.push(c);
			}
		}
		while (!q.isEmpty() && palindrome)
		{
			
			char q1 = q.dequeue();
			char s1 = s.top();
			s.pop();
			if (q1 != s1)
			{
				palindrome = false;

			}
		}
		if (palindrome)
		{
			cout << endl << "** Is a palindrome **\n";
		}
		else if (!palindrome)
		{
			cout << endl << input << endl << "**Is NOT a palindrome\n";
		}

		num--;
			
	}
	
	cout << "\nNo more strings left.\n";
	system("pause");
	return 0;
}
int main1()
{
	StringQueue Q;
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);
	Q.enqueue(5);
	Q.enqueue(6);
	Q.enqueue(7);
	Q.enqueue(8);
	Q.enqueue(9);
	Q.enqueue(0);


	while (!Q.isEmpty())
	{
		cout << Q.dequeue() << "\n";
	}
	cout << endl;
	
	return 0;
}

