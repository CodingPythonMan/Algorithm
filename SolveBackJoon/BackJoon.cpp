#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int* queues = new int[10000];
	int front = 0;
	int back = 0;
	int commandCount = 0;

	cin >> commandCount;

	char command[10];
	int value;
	for (int i = 0; i < commandCount; i++)
	{
		memset(command, 0, 10);
		cin >> command;

		if (strcmp(command, "push") == 0)
		{
			cin >> value;
			queues[back] = value;
			back++;
		}
		else if (strcmp(command, "pop") == 0)
		{
			if (back - front > 0)
			{
				cout << queues[front] << "\n";
				front++;
			}
			else
				cout << -1 << "\n";
		}
		else if (strcmp(command, "front") == 0)
		{
			if (back - front > 0)
				cout << queues[front] << "\n";
			else
				cout << -1 << "\n";
		}
		else if (strcmp(command, "back") == 0)
		{
			if (back - front > 0)
				cout << queues[back-1] << "\n";
			else
				cout << -1 << "\n";
		}
		else if (strcmp(command, "size") == 0)
		{
			cout << back - front << "\n";
		}
		else if (strcmp(command, "empty") == 0)
		{
			if (back - front == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}
}