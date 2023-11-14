#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void BOJ1436_SHAWM()
{
	int n;
	cin >> n;

	int num = 0;
	int answer = 666;

	while (true)
	{
		string str = to_string(answer);
		int ans = 0;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '6')
				ans++;
			else
				ans = 0;

			if (ans > 2)
			{
				num++;
				break;
			}
		}

		if (num == n)
			break;

		answer++;
	}

	cout << answer;
}

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

void BOJ1920_FindNumber()
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

	sort(arr, arr + n);

	for (int i = 0; i < m; i++)
	{
		if (BinarySearch(arr, 0, n - 1, arr2[i]) >= 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}

void BOJ1978_FindSosu()
{
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int sosuList[1001] = { 0 };

	for (int i = 2; i < 1001; i++)
	{
		if (sosuList[i] == 2)
			continue;

		sosuList[i] = 1;
		for (int j = i + 1; j < 1001; j++)
		{
			if (j % i == 0)
				sosuList[j] = 2;
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
		if (sosuList[arr[i]] == 1)
			answer++;

	cout << answer << "\n";
}

int n, r, c;
int result;

void Search(int y, int x, int size)
{
	if (y == r && x == c)
	{
		cout << result << "\n";
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x)
	{
		Search(y, x, size / 2);
		Search(y, x + size / 2, size / 2);
		Search(y + size / 2, x, size / 2);
		Search(y + size / 2, x + size / 2, size / 2);
	}
	else
	{
		result += size * size;
	}
}

void BOJ1074_Z()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> r;
	cin >> c;

	Search(0, 0, (1 << n));
}

struct Client
{
	int age;
	char name[101];
	int order;
};

int order = 0;

void Swap(Client& a, Client& b)
{
	Client temp = a;
	a = b;
	b = temp;
}

void QuickSort(Client* clients, int left, int right)
{
	if (left >= right)
		return;

	Client* pivot = &clients[right];
	int low = left;

	for (int high = left; high < right; high++)
	{
		if (clients[high].age > pivot->age)
		{
			continue;
		}

		if (clients[high].age == pivot->age && clients[high].order > pivot->order)
		{
			continue;
		}

		Swap(clients[low], clients[high]);
		low++;
	}
	Swap(clients[low], *pivot);

	QuickSort(clients, left, low - 1);
	QuickSort(clients, low + 1, right);
}

void BOJ10814_Age()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	Client* clients = new Client[n];

	for (int i = 0; i < n; i++)
	{
		cin >> clients[i].age;
		cin >> clients[i].name;
		clients[i].order = order;
		order++;
	}

	QuickSort(clients, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << clients[i].age << " " << clients[i].name << "\n";
	}

	delete[] clients;
}