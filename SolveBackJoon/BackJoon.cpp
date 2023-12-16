#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> Stack;

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	char* output = new char[100000];

	int num = 1;
	int order = 0;
	while (1)
	{
		if (Stack.top() == arr[order])
		{
		}
		else if (Stack.top() == arr[order])
		{

		}
		else
		{
			Stack.push(num);
		}

		if (j == n)
		{
			break;
		}

		num++;
	}

	for (int i = 0; i < j; i++)
	{

	}

	cout << "NO";
}