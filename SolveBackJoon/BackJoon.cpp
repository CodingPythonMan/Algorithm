#include <iostream>
using namespace std;

int main()
{
	int A, B, V;

	cin >> A >> B >> V;

	int dayWork = A - B;
	int days = (V - A) / dayWork + 1;

	if ((V - A) % dayWork != 0)
		days += 1;

	cout << days << "\n";
}