#include <climits>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<long> distances;
vector<int> visibles;
vector<vector<pair<int, long>>> graph;

void explorer(int start)
{
	auto cmp = [](const pair<int, long>& p1, const pair<int, long>& p2) {
		return (p1.second > p2.second);
	};

	priority_queue<pair<int, long>, vector<pair<int, long>>, decltype(cmp)> pq(cmp);
	distances[start] = 0;
	pq.push({ start, 0 });

	//  Q 에 G의 모든 정점들을 넣는다.
	while (pq.size() != 0)
	{
		const pair<int, long> node = pq.top();
		pq.pop();

		if (node.second > distances[node.first])
			continue;

		for (auto& next : graph[node.first])
		{
			if (visibles[next.first] == 0 && distances[next.first] > node.second + next.second)
			{
				distances[next.first] = node.second + next.second;
				pq.push({ next.first, distances[next.first] });
			}
		}
	}
}

int main()
{
	int n, e;
	cin >> n >> e;

	distances.resize(n);
	visibles.resize(n);
	graph.resize(n);

	for (int i = 1; i < n; i++)
		distances[i] = LONG_MAX;

	for (int i = 0; i < n; i++)
		cin >> visibles[i];
	visibles[n - 1] = 0;
	
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	explorer(0);

	if (distances[n - 1] == LONG_MAX)
		cout << -1;
	else
		cout << distances[n - 1];
}