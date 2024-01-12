#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	string sen;
	cin >> sen;

	// 50글자 이내
	vector<char> oper;
	vector<int> num;
	int numCount = 0;
	for (int i = 0; i < sen.length(); i++)
	{
		if (sen[i] == '+' || sen[i] == '-')
		{
			atoi(sen.substr(numCount, i - 1));
			numCount = i;
		}
	}

	cout << sen;
}