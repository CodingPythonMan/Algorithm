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

void init(int n)
{
	for (int i = 1; i < n + 1; i++)
		distances[i] = INT_MAX;

	for (int i = 1; i < n + 1; i++)
		visit[i] = false;
}

void explorer(const int arrive, const int before)
{
	const vector<vertex>& links = linkList[arrive];

	auto cmp = [](const vertex& v1, const vertex& v2) {
		return (v1.w > v2.w);
	};

	priority_queue < vertex, vector<vertex>, decltype(cmp)> pq(cmp);

	for (int i = 0; i < links.size(); i++)
	{
		const vertex& v = links[i];
		if (visit[v.n] == true)
			continue;

		if (distances[v.n] > v.w + before)
			distances[v.n] = v.w + before;

		if (linkList[v.n].empty() == false)
		{
			pq.push({ v.n, distances[v.n] });
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
	int n, e, param1, param2, result;
	//cin >> n >> e;
	n = 4;
	e = 6;
	param1 = 2;
	param2 = 3;
	result = 0;

	linkList.resize(n + 1);
	visit.resize(n + 1);
	distances.resize(n + 1);

	init(n);

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

	visit[1] = true;
	distances[1] = 0;
	explorer(1, 0);

	if (distances[param1] < distances[param2])
	{
		result += distances[param1];
		init(n);
		explorer(param1, 0);
		result += distances[param2];
		init(n);
		explorer(param2, 0);
	}
	else
	{
		result += distances[param2];
		init(n);
		explorer(param2, 0);
		result += distances[param1];
		init(n);
		explorer(param1, 0);
	}

	result += distances[n];

	if (visit[n] == true)
		cout << result;
	else
		cout << -1;
}