#include <iostream>
using namespace std;

int Constructor(int num)
{
	int value = num;
	for (int i = 0; value > 0; i++)
	{
		num += (value % 10);
		value /= 10;
	}
	
	return num;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = Constructor(i);
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == n)
		{
			cout << i << "\n";
			delete[] arr;
			return 0;
		}
	}

	cout << 0 << "\n";

	delete[] arr;
}