#include <iostream>
using namespace std;

struct Client
{
	int age;
	char name[100];
	int order;
};

int order = 0;

void QuickSort(Client* clients, int left, int right)
{
	while (left < right)
	{
		Client* pivot = &clients[left];
		int low = left + 1;
		int high = right;

		while (low <= high)
		{
			while (pivot->age >= clients[low].age)
			{
				if (pivot->age == clients[low].age && pivot->order >= clients[low].order)
				{
					break;
				}

				low++;
			}

			while (pivot->age <= clients[high].age)
			{
				if (pivot->age == clients[high].age && pivot->order <= clients[high].order)
				{
					break;
				}

				high--;
			}

			if (low <= high)
			{
				Client temp = clients[low];
				clients[low] = clients[high];
				clients[high] = temp;
			}
		}

		Client temp = *pivot;
		*pivot = clients[high];
		clients[high] = temp;

		QuickSort(clients, left, high - 1);
		QuickSort(clients, high + 1, right);
	}
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
		cout << clients[i].age << clients[i].name << "\n";
	}

	delete[] clients;
}