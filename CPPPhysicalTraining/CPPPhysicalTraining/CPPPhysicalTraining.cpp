#include <climits>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct node
{
	int index;
	int weight;
};

vector<vector<node>> linkList;
vector<bool> visit;
vector<int> distances;

void explorer(const node& vertex)
{
	vector<node>& links = linkList[vertex.index];

	auto cmp = [](const node& v1, const node& v2) {
		return (v1.weight > v2.weight);
	};

	priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < static_cast<int>(links.size()); i++)
	{
		const node& v = links[i];

		if (visit[v.index] == true)
			continue;

		if (distances[v.index] > vertex.weight + v.weight)
			distances[v.index] = vertex.weight + v.weight;

		if (linkList[v.index].empty() == false)
			pq.push({ v.index, distances[v.index] });
	}

	if (pq.size() != 0)
	{
		const node& v = pq.top();
		visit[v.index] = true;
		explorer(v);
	}
}

int main()
{
	int n, e;
	cin >> n >> e;

	linkList.resize(n);
	visit.resize(n);
	distances.resize(n);

	for (int i = 1; i < n; i++)
		distances[i] = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		int visible;
		cin >> visible;
		if (visible == 1)
			visit[i] = true;
	}
	visit[n - 1] = false;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		linkList[a].push_back({ b,c });
		linkList[b].push_back({ a,c });
	}

	visit[0] = true;
	explorer({ 0,0 });

	if (distances[n - 1] == INT_MAX)
		cout << -1;
	else
		cout << distances[n - 1];
}