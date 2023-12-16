#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	stack<int> Stack;

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<char> commands;

	int num = 1;
	int order = 0;
	int command = 0;
	while (1)
	{
		if (Stack.size() != 0)
		{
			if (Stack.top() > arr[order])
			{
				cout << "NO";
				return 0;
			}
			else if (Stack.top() == arr[order])
			{
				Stack.pop();
				commands.push_back('-');
				command++;
				order++;
			}
			else
			{
				Stack.push(num);
				commands.push_back('+');
				command++;
				num++;
			}
		}
		else
		{
			Stack.push(num);
			commands.push_back('+');
			command++;
			num++;
		}

		if (order == n)
		{
			break;
		}
	}

	for (int i = 0; i < command; i++)
	{
		cout << commands[i] << "\n";
	}

	return 0;
}