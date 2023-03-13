#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct vertex {
	int n;
	int w;
};

vector<vector<vertex>> linkList;
vector<bool> visit;
vector<int> distances;

void explorer(const int arrive, const int before)
{
	const vector<vertex>& links = linkList[arrive];

	auto cmp = [](const vertex& v1, const vertex& v2) {
		return (v1.n > v2.n);
	};

	priority_queue < vertex, vector<vertex>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < links.size(); i++)
	{
		const vertex& v = links[i];
		if (visit[v.n] == true)
			continue;

		if (distances[arrive] > v.w + before)
			distances[arrive] = v.w + before;

		if (linkList[v.n].empty() == false)
		{
			pq.push({ v.n, distances[arrive] });
		}
			
	}

	if (pq.size() != 0)
	{
		const vertex& v = pq.top();
		visit[v.n] = true;
		explorer(v.n, v.w);
	}
}

int main()
{
	int n, e, start, end;
	//cin >> n >> e;
	n = 4;
	e = 6;
	start = 2;
	end = 3;

	linkList.resize(n + 1);
	visit.resize(n + 1);
	distances.resize(n + 1);

	for (int i = 1; i < n + 1; i++)
		distances[i] = INT_MAX;

	/*for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		linkList[a].push_back({ b,c });
	}
	cin >> start >> end;*/
	linkList[1].push_back({ 2,3 });
	linkList[2].push_back({ 1,3 });
	linkList[2].push_back({ 3,3 });
	linkList[3].push_back({ 2,3 });
	linkList[3].push_back({ 4,1 });
	linkList[4].push_back({ 3,1 });
	linkList[1].push_back({ 3,5 });
	linkList[3].push_back({ 1,5 });
	linkList[2].push_back({ 4,5 });
	linkList[4].push_back({ 2,5 });
	linkList[1].push_back({ 4,4 });
	linkList[4].push_back({ 1,4 });

	visit[start] = true;
	explorer(start, 0);

	if (visit[end] == true)
		cout << distances[end];
	else
		cout << -1;
}