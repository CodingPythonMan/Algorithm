#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int target;

	cin >> n >> target;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int min = 9999999;
	int sum = 0;
	int answer = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];

				if (target - sum < min && target - sum >= 0)
				{
					min = target - sum;
					answer = sum;
				}
			}
		}
	}

	cout << answer;
}