#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Vector[102];
int Count = 0;

void BFS(int Start, int End)
{
	bool visit[102] = {0};
	queue<pair<int, int>> Queue;

	Queue.push(make_pair(Start, 0));
	while (Queue.empty() == false)
	{
		pair<int, int> Route = Queue.front();
		Queue.pop();

		if (Route.first == End)
		{
			Count = Route.second;
			break;
		}
		else
		{
			for (int i = 0; i < Vector[Route.first].size(); i++)
			{	
				int middleEnd = Vector[Route.first][i];

				if (visit[middleEnd] == 1)
					continue;
				else
					visit[middleEnd] = 1;
					
				Queue.push(make_pair(middleEnd, Route.second + 1));
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	int Answer[102] = {0};
	int Start, End;
	for (int i = 0; i < m; i++)
	{
		cin >> Start >> End;
		Vector[Start].push_back(End);
		Vector[End].push_back(Start);
	}
	
	int Min = 1000000000;
	int count = 0;
	for (int i = 1; i < n+1; i++)
	{
		count = 0;
		for (int j = 1; j < n + 1; j++)
		{
			if (i == j)
				continue;

			BFS(i, j);
			count += Count;
		}

		if (Min > count)
			Min = count;

		Answer[i] = count;
	}

	for (int i = 1; i < 102; i++)
	{
		if (Answer[i] == Min)
		{
			cout << i << "\n";
			return 0;
		}
	}
}