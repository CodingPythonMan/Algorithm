#include <iostream>
#include <vector>
using namespace std;

struct Doc
{
	int Order;
	int Data;
};

int main()
{
	int test;
	cin >> test;
	vector<Doc> Queue;
	for (int i = 0; i < test; i++)
	{
		int n, m;
		cin >> n >> m;

		int num;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			Doc doc;
			doc.Order = j;
			doc.Data = num;
			Queue.push_back(doc);
		}

		Doc front;
		int loop = 0;
		while (1)
		{
			front = Queue[0];

			bool right = false;
			for (int j = 0; j < Queue.size(); j++)
			{
				if (front.Data < Queue[j].Data)
				{
					Queue.erase(Queue.begin());
					Queue.push_back(front);
					right = true;
					break;
				}
			}

			if (right)
				continue;

			Queue.erase(Queue.begin());
			loop++;

			if (m == front.Order)
			{
				break;
			}
		}

		Queue.clear();
		cout << loop << "\n";
	}
}