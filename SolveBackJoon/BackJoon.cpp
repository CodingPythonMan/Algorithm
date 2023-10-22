#include <iostream>
using namespace std;

int BinarySearch(int arr[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;

	mid = (first + last) / 2;

	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return BinarySearch(arr, first, mid - 1, target);
	else
		return BinarySearch(arr, mid + 1, last, target);
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

	

	for (int i = 0; i < m; i++)
	{
		cout << BinarySearch(arr, 0, n, arr2[i]) << "\n";
	}
}