#include "pch.h"
#include "DelayNetwork.h"

int DelayNetwork::networkDelayTime(vector<vector<int>>& times, int n, int k) {
	distances.resize(n + 1);
	linkList.resize(n + 1);
	weightList.resize(n + 1);

	for (int i = 0; i < n + 1; i++)
		distances[i] = INT_MAX;

	for (const vector<int>& i : times)
	{
		linkList[i[0]].push_back(i[1]);
		weightList[i[0]].push_back(i[2]);
	}

	distances[k] = 0;

	Explorer(k, 0);

	int result = 0;

	for (int i=1; i<n+1; i++)
	{
		if (distances[i] == INT_MAX)
		{
			result = -1;
			break;
		}
		if (result < distances[i])
			result = distances[i];
	}

	return result;
}

void DelayNetwork::Explorer(const int k, int weight)
{
	const vector<int>& links = linkList[k];
	const vector<int>& weights = weightList[k];

	auto cmp = [](const vector<int>& v1, const vector<int>& v2)
	{
		return (v1[1] > v2[1]);
	};

	priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

	for (int i=0; i<links.size(); i++)
	{
		int index = links[i];

		if (distances[index] > weights[i] + weight)
		{
			distances[index] = weights[i] + weight;
		}

		pq.push({ links[i],distances[index]});
	}

	while (pq.size() != 0)
	{
		const vector<int>& vertex = pq.top();
		
		if (linkList[vertex[0]].empty())
		{
			pq.pop();
			continue;
		}

		Explorer(vertex[0], weight + vertex[1]);
		break;
	}
}