#include <iostream>
using namespace std;

struct Client
{
	int age;
	char name[100];
	int order;
};

int order = 0;

int CompareClient(Client& a, Client& b)
{
	if (a.age < b.age)
	{
		return 1;
	}
	else if (a.age == b.age)
	{
		if (a.order < b.order)
		{
			return 1;
		}
		else
			return -1;
	}
	else
	{
		return -1;
	}
}

void MergeSort(Client* clients, int first, int end)
{
	if (first >= end)
		return;

	int mid = (first + end) / 2;

	MergeSort(clients, first, mid);
	MergeSort(clients, mid + 1, end);

	int left = first;
	int right = mid+1;
	int index = first;
	Client* clientList = new Client[end-first+1];

	while (left <= mid && right <= end)
	{
		if (CompareClient(clients[left], clients[right]) < 0)
		{
			clientList[index] = clients[left];
			left++;
			index++;
		}
		else
		{
			clientList[index] = clients[right];
			right++;
			index++;
		}
	}

	if (left > mid)
	{
		for (int i = right; i <= end; i++)
		{
			clientList[index] = clients[i];
			index++;
		}
	}
	else
	{
		for (int i = left; i <= mid; i++)
		{
			clientList[index] = clients[i];
			index++;
		}
	}

	for (int i = first; i <= end; i++)
		clients[i] = clientList[i];

	delete[] clientList;
}

int main()
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

	MergeSort(clients, 0, n-1);

	for (int i = 0; i < n; i++)
	{
		cout << clients[i].age << " " << clients[i].name << "\n";
	}

	delete[] clients;
}