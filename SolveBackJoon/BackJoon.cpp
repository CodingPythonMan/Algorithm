#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int num;
	priority_queue<int, vector<int>, greater<int>> Queue;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		if (num == 0)
		{
			if (Queue.empty() == true)
			{
				cout << 0 << "\n";
				continue;
			}

			num = Queue.top();
			Queue.pop();
			cout << num << "\n";
		}
		else
		{
			Queue.push(num);
		}
	}
}