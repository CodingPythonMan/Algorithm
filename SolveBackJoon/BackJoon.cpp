#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		string str;
		cin >> str;

		if (str.compare("0") == 0)
			break;

		bool answer = false;

		string cmpStr = str;
		for (size_t i = 0; i < str.length(); i++)
		{
			cmpStr[str.length()-1 - i] = str[i];
		}

		if (cmpStr.compare(str) == 0)
			answer = true;
		else
			answer = false;

		if (answer)
		{
			cout << "yes" << "\n";
		}
		else
		{
			cout << "no" << "\n";
		}
	}
}