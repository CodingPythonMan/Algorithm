#include <iostream>
using namespace std;

void BOJ1008_AB()
{
	double a;
	double b;

	cin >> a;
	cin >> b;

	cout.precision(15);
	cout << a / b;
}

void BOJ1330_AB()
{
	int a;
	int b;

	cin >> a;
	cin >> b;

	if (a < b)
	{
		cout << "<";
	}
	else if (a == b)
	{
		cout << "==";
	}
	else
	{
		cout << ">";
	}
}

void BOJ10250_ACMHotel()
{
	int n;
	cin >> n;

	int* answer = new int[n];

	for (int i = 0; i < n; i++)
	{
		int a;
		int b;
		int c;

		cin >> a;
		cin >> b;
		cin >> c;

		int floor = c % a;
		int nd = c / a;

		if (floor == 0)
		{
			floor = a;
		}
		else
		{
			nd++;
		}

		answer[i] = floor * 100 + nd;
	}

	for (int i = 0; i < n; i++)
		cout << answer[i] << "\n";
}