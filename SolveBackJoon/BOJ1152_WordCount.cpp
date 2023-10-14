#include <string>
#include <iostream>
using namespace std;

void WordCount()
{
	string str;
	int answer = 0;

	getline(cin, str);

	bool nextSpace = false;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (nextSpace == true)
		{
			if (str[i] == ' ')
				nextSpace = false;
		}

		if (nextSpace == false && str[i] != ' ')
		{
			answer++;
			nextSpace = true;
		}
	}

	cout << answer;
}