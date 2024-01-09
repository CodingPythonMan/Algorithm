#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> dp;
bool btnList[10] = { false };

bool check(int now) 
{
	string target = to_string(now);
	for (int i = 0; i < target.length(); i++)
	{
		if (true == btnList[target[i] - 48])
			return false;
	}
	return true;
}

int main() {
	int n, banBtnCount;
	cin >> n >> banBtnCount;

	int ban;

	for (int i = 0; i < banBtnCount; i++) 
	{
		cin >> ban;
		btnList[ban] = true;
	}

	int minimum = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) 
	{
		if (true == check(i)) 
		{
			int tmp = abs(n - i) + (int)(to_string(i).length());
			minimum = min(minimum, tmp);
		}
	}

	cout << minimum << endl;

	return 0;
}