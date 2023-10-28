#include <iostream>
using namespace std;

void swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = arr[index1];
}

void QuickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot > arr[low])
			low++;

		while (pivot < arr[high])
			high--;

		if(low < high)
			swap(arr[low], arr[high]);
	}
	swap(arr[left], arr[high]);

	QuickSort(arr, left, high - 1);
	QuickSort(arr, high + 1, right);
}

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

	QuickSort(arr, 0, n-1);

	for (int i = 0; i < m; i++)
	{
		if(BinarySearch(arr, 0, n, arr2[i]) >= 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}