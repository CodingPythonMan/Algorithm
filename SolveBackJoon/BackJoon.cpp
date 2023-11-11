#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int a, b, c;

		cin >> a >> b >> c;
		
		if (a == 0 && b == 0 && c == 0)
			break;

		if (a * a == b * b + c * c)
		{
			cout << "right\n";
			continue;
		}
		else if (c * c == a * a + b * b)
		{
			cout << "right\n";
			continue;
		}
		else if (b * b == a * a + c * c)
		{
			cout << "right\n";
			continue;
		}

		cout << "wrong\n";
	}
}