#include <iostream>
using namespace std;

int compareStr(string* a, string* b)
{
	if (a->length() > b->length())
	{
		return 1;
	}
	else if (a->length() == b->length())
	{
		for (size_t i = 0; i < a->length(); i++)
		{
			if ((*a)[i] > (*b)[i])
			{
				return 1;
			}
			else if ((*a)[i] < (*b)[i])
			{
				return -1;
			}
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

void MergeSort(string strArr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(strArr, left, mid);
		MergeSort(strArr, mid + 1, right);

		int first = left;
		int rightFirst = mid + 1;
		int side = left;

		string* sortStr = new string[right + 1];

		while (first <= mid && rightFirst <= right)
		{
			if (compareStr(&strArr[first], &strArr[rightFirst]) <= 0)
			{
				sortStr[side] = strArr[first];
				first++;
			}
			else
			{
				sortStr[side] = strArr[rightFirst];
				rightFirst++;
			}

			side++;
		}

		if (first > mid)
		{
			for (int i = rightFirst; i <= right; i++, side++)
			{
				sortStr[side] = strArr[i];
			}
		}
		else
		{
			for (int i = first; i <= mid; i++, side++)
			{
				sortStr[side] = strArr[i];
			}
		}

		for (int i = left; i < right + 1; i++)
			strArr[i] = sortStr[i];

		delete[] sortStr;
	}
}

void BOJ1181_Sort()
{
	int n;
	cin >> n;

	string* str = new string[n];

	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	MergeSort(str, 0, n - 1);

	string repeat = "";
	for (int i = 0; i < n; i++)
	{
		if (repeat.compare(str[i]) == 0)
		{
			continue;
		}

		cout << str[i] << "\n";
		repeat = str[i];
	}
}