#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	string sen;
	cin >> sen;

	int answer = 0;

	// 50글자 이내
	int numCount = 0;
	int value;
	bool minusFlag = false;
	for (int i = 0; i < sen.length(); i++)
	{
		if (sen[i] != '+' && sen[i] != '-' && i != sen.length() - 1)
			continue;

		value = atoi(sen.substr(numCount, i - numCount + 1).c_str());
		if (i != sen.length() - 1)
			numCount = i + 1;
			
		if (minusFlag == false)
			answer += value;
		else
			answer -= value;

		if (sen[i] == '-')
			minusFlag = true;
	}

	cout << answer << "\n";
}