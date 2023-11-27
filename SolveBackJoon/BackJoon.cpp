#include <iostream>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	int** num = new int*[n+1];
	for (int i = 0; i < n+1; i++)
	{
		num[i] = new int[n+1];
	}

	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < k+1; j++)
		{
			if (i == j || i == 0 || j == 0)
			{
				num[i][j] = 1;
				continue;
			}

			num[i][j] = num[i-1][j-1] + num[i-1][j];
		}
	}

	cout << num[n][k] << "\n";

	for (int i = 0; i < n; i++)
	{
		delete[] num[i];
	}
	delete[] num;
}