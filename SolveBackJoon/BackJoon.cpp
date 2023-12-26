#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M = 1234567891;
	int r = 31;

	string String;

	int n;
	cin >> n;
	unsigned long long sum = 0;
	cin >> String;
	for (int i = 0; i < n; i++)
	{
		unsigned long long num = String[i] - 'a' + 1;
		for (int j = 0; j < i; j++)
		{
			num *= r;
			num %= M;
		}

		sum += num;
	}

	cout << sum % M << "\n";
}