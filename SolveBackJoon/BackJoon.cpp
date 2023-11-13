#include <iostream>
using namespace std;

struct Client
{
	int age;
	char name[100];
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

	QuickSort(clients, 0, n-1);

	for (int i = 0; i < n; i++)
	{
		cout << clients[i].age << " " << clients[i].name << "\n";
	}

	delete[] clients;
}