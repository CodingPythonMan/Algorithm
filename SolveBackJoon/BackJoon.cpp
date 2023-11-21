#include <iostream>
#include <string.h>
using namespace std;

int stacks[10000];
int stackIndex = 0;

int main()
{
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
			stacks[stackIndex] = value;
			stackIndex++;
		}
		else if (strcmp(command, "pop") == 0)
		{
			if (stackIndex > 0)
			{
				stackIndex--;
				cout << stacks[stackIndex] << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else if (strcmp(command, "top") == 0)
		{
			if (stackIndex > 0)
				cout << stacks[stackIndex - 1] << "\n";
			else
				cout << -1 << "\n";
		}
		else if (strcmp(command, "size") == 0)
		{
			cout << stackIndex << "\n";
		}
		else if (strcmp(command, "empty") == 0)
		{
			if (stackIndex == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}
}