#include <regex>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (true) {

		getline(cin, str);
		if (str == "")
			break;
		//regex e("^cat$");
		//regex e("gr[ea]y");
		//regex e("Jeffrey|Jeffery");
		//regex e("Jeff(re|er)y");
		//regex e("(Geo|Je)ff(re|er)y");
		//regex e("colou?r");
		//regex e("[0-9]{3}[-.][0-9]{3}[-.][0-9]{4}");
		//regex e("[0-9]{3} *([-.])[0-9]{3}\\1 *[0-9]{4}");
		//regex e3("(July|Jul) (4th|4|fourth)");
		//regex e("July? (4(th)?|fourth)");
		//regex e("a{3}c+b?");
		//regex e("a|b|c");
		//regex e("h[^eai]l.lo");
		//regex e("^(ca)?t{3,}\\1");
		//regex e("[0-9]{3} *([-.])?[0-9]{3}\\1 *[0-9]{4}");
		//regex e("^([1][0-2]|[1-9]):[0-5][0-9] ?(am|pm)");
		regex e("^a{4}[xy]+$");
		bool match = regex_search(str, e);
		cout << (match ? "Matched" : "Not matched") << endl << endl;
	}
	return 0;
}