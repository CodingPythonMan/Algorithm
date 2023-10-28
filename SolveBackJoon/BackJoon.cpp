#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int arr[], int first, int last, int target)
{
	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			last = mid - 1;
		else
			first = mid + 1;
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int m;
	cin >> m;
	int* arr2 = new int[m];
	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}

	sort(arr, arr+n);

	for (int i = 0; i < m; i++)
	{
		if(BinarySearch(arr, 0, n-1, arr2[i]) >= 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}