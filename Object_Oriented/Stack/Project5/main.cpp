#include "PostFixEval.h"

int main()
{
	string Exp = " ";
	bool done = false;
	string Token[MAX];
	size_t count = 0;
	Stack stk;
	while (!done)
	{
		cout << "Please enter the postfix expression: ";
		getline(cin, Exp);
		TokenizerParser::getStringArray(Token, Exp, MAX, count);
		for (int i = 0; i < count; i++)
		{
			if (Token[i] == "+")
			{
				ItemType I1 = stk.top();
				stk.pop();
				ItemType I2 = stk.top();
				stk.pop();
				double result = I2.Double + I1.Double;
				ItemType I3;
				I3.Double = result;
				stk.push(I3);
			}
			else if (Token[i] == "-")
			{
				ItemType I1 = stk.top();
				stk.pop();
				ItemType I2 = stk.top();
				stk.pop();
				double result = I2.Double - I1.Double;
				ItemType I3;
				I3.Double = result;
				stk.push(I3);
			}
			else if (Token[i]=="*")
			{
				ItemType I1 = stk.top();
				stk.pop();
				ItemType I2 = stk.top();
				stk.pop();
				double result = I2.Double * I1.Double;
				ItemType I3;
				I3.Double = result;
				stk.push(I3);
			}
			else if (Token[i] == "/")
			{
				ItemType I1 = stk.top();
				stk.pop();
				ItemType I2 = stk.top();
				stk.pop();
				double result = I2.Double / I1.Double;
				ItemType I3;
				I3.Double = result;
				stk.push(I3);
			}
			else
			{
				double val = TokenizerParser::parseDouble(Token[i]);
				ItemType I1;
				I1.Double = val;
				stk.push(I1);
			}

		}
		double Final = 0;
		Final = (stk.top()).Double;
		stk.pop();
		cout << "The expression: " << Exp << " = " << Final << endl;
		cout << "Enter 0 for more Data, 1 to exit: ";
		cin >> done;
		cout << endl;

	}
	system("pause");
	return 0;
}