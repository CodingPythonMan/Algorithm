#include "pch.h"
#include "DelayNetwork.h"

int DelayNetwork::networkDelayTime(vector<vector<int>>& times, int n, int k) 
{
	graph.resize(n + 1);
	distances.resize(n + 1);

	for (int i = 1; i < n + 1; i++)
		distances[i] = INT_MAX;

	for (int i = 0; i < static_cast<int>(times.size()); i++)
	{
		const vector<int>& time = times[i];

		graph[time[0]].push_back({ time[1], time[2] });
		// 무방향성 일 때는 하나 더 추가
	}

	Explorer(k);

	int result = 0;
	for (int i = 1; i < n + 1; i++)
	{
		if (distances[i] == INT_MAX)
		{
			result = -1;
			break;
		}

		if(result < distances[i])
			result = distances[i];
	}

	return result;
}

void DelayNetwork::Explorer(int start)
{
	distances[start] = 0;

	auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
		return (p1.second > p2.second);
	};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
	pq.push({ start, 0 });

	while (pq.size() != 0)
	{
		pair<int, int> node = pq.top();
		pq.pop();

		if (node.second > distances[node.first]) continue;

		for (auto& next : graph[node.first])
		{
			if (distances[next.first] > node.second + next.second)
			{
				distances[next.first] = node.second + next.second;
				pq.push({ next.first, distances[next.first] });
			}
		}
	}
}