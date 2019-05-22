#include "Fration.h"

Fraction::Fraction(long top, long bottom) : numerator(top)
{
	if (bottom == 0)
	{
		cout << "Numerator cannot be 0\n";
	}
	else
	{
		denomenator = bottom;
	}
	normalize();
}
const string Fraction::toString()
{
	ostringstream os;
	os << numerator << "/" << denomenator;
	return os.str();
}
long Fraction::gcd(long a, long b)
{
	int remainder;
	a = abs(a);
	b = abs(b);

	while (b != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}

	return a;
}
void Fraction::normalize()
{
	long reduce = gcd(numerator, denomenator);
	numerator /= reduce;
	denomenator /= reduce;
	if (numerator < 0 && denomenator < 0)
	{
		numerator = numerator * -1;
		denomenator = denomenator * -1;
	}
	else if (numerator > 0 && denomenator < 0)
	{
		numerator = numerator * -1;
		denomenator = denomenator * -1;
	}
}
const long Fraction::getBottom() const
{
	return denomenator;
}
const long Fraction::getTop() const
{
	return numerator;
}

const Fraction operator+ (const Fraction & num1, const Fraction & num2)
{
	
	int Bottom = num1.getBottom() * num2.getBottom();
	int Top = num1.getTop() * num2.getBottom();
	int Top1 = num2.getTop() * num1.getBottom();
	Fraction sum((Top + Top1), Bottom);
	return sum;
}
const Fraction operator- (const Fraction & num1, const Fraction & num2)
{
	int Bottom = num1.getBottom() * num2.getBottom();
	int Top = num1.getTop() * num2.getBottom();
	int Top1 = num2.getTop() * num1.getBottom();
	Fraction subtract((Top - Top1), Bottom);
	return subtract;
}
const Fraction operator * (const Fraction & num1, const Fraction & num2)
{
	Fraction multi((num1.getTop()*num2.getTop()), (num1.getBottom()*num2.getBottom()));
	return multi;
}
const Fraction operator/ (const Fraction & num1, const Fraction & num2)
{
	Fraction divide((num1.getTop()*num2.getBottom()), (num1.getBottom()*num2.getTop()));
	return divide;
}
bool operator== (const Fraction & num1, const Fraction & num2)
{
	if ((num1.getTop() == num2.getTop()) && (num1.getBottom() == num2.getBottom()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!= (const Fraction & num1, const Fraction & num2)
{
	if ((num1.getTop() != num2.getTop()) || (num1.getBottom() != num2.getBottom()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
ostream & operator<< (ostream & output, const Fraction & num)
{
	output << num.getTop() << "/" << num.getBottom();
	return output;
	
}
istream & operator>> (istream & input, Fraction & num)
{
	string typeIfstream = typeid(input).name();
	string typeCin = typeid(cin).name();
	int top, bot;
	bool flag = true;
	if (typeIfstream.find(string("ifstream")) != string::npos) {
		flag = false;
	}

	if (typeCin.find(string("cin")) != string::npos) {
		flag = true;
	}

	if (!flag) {
		input >> top >> bot;
		num = Fraction(top, bot);
	}

	if (flag) {
		cout << "Enter the numerator: ";
		cin >> top;
		cout << "Enter the denomenator: ";
		cin >> bot;
		num = Fraction(top, bot);
	}

	return input;
}
const Fraction Fraction::operator-()
{
	return Fraction((numerator*-1), denomenator);
}
const Fraction Fraction::operator--()
{
	numerator -= denomenator;
	return Fraction(numerator, denomenator);
}
const Fraction Fraction::operator--(int maker)
{
	Fraction temp;
	temp.numerator = numerator;
	temp.denomenator = denomenator;
	numerator -= denomenator;
	return Fraction(temp.numerator, temp.denomenator);
}
const Fraction Fraction::operator++()
{
	numerator += denomenator;
	return Fraction(numerator, denomenator);
}
const Fraction Fraction::operator++(int maker)
{
	Fraction temp;
	temp.numerator = numerator;
	temp.denomenator = denomenator;
	numerator += denomenator;
	return Fraction(temp.numerator, temp.denomenator);
}
double Fraction::toDouble()
{
	return static_cast<double>(numerator) / static_cast<double>(denomenator);
}