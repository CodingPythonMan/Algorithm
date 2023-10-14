#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string* str = new string[n];

	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 2; j++)
		{
			string tempStr;

			if (str[i].length() > str[i + 1].length())
			{
				tempStr = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tempStr;
			}
			else if (str[i].length() == str[i + 1].length())
			{
				for (int k = 0; k < str[i].length(); k++)
				{
					if (str[k] == str[k + 1])
					{

					}
				}
			}
		}
	}
}