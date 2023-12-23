#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int k, n;
	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;
		int** secArr = new int*[k + 1];
		for (int j = 0; j < k + 1; j++)
		{
			secArr[j] = new int[n + 1];
		}

		for (int ho = 0; ho < n + 1; ho++)
		{
			secArr[0][ho] = ho;
		}

		for (int floor = 1; floor < k + 1; floor++)
		{
			secArr[floor][1] = 1;
			secArr[floor][0] = 0;
		}

		for (int j = 1; j < k + 1; j++)
		{
			for (int ho = 1; ho < n + 1; ho++)
			{
				secArr[j][ho] = secArr[j-1][ho] + secArr[j][ho-1];
			}
		}

		cout << secArr[k][n] << "\n";
		for (int j = 0; j < k; j++)
			delete[] secArr[j];

		delete[] secArr;
	}
}