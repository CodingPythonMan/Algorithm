#include "pch.h"
#include "DelayNetwork.h"

int DelayNetwork::networkDelayTime(vector<vector<int>>& times, int n, int k) {
	distances.resize(n + 1);
	visit.resize(n + 1);
	linkList.resize(n + 1);
	weightList.resize(n + 1);

	for (int i = 0; i < n + 1; i++)
		distances[i] = INT_MAX;

	for (const vector<int>& i : times)
	{
		linkList[i[0]].push_back(i[1]);
		weightList[i[0]].push_back(i[2]);
	}

	visit[k] = true;
	distances[k] = 0;

	Explorer(k, 0);

	int result = INT_MAX;

	for (int i : distances)
	{
		if (i == INT_MAX)
		{
			result = -1;
			break;
		}
		if (result > i)
			result = i;
	}

	return result;
}

void DelayNetwork::Explorer(const int k, int weight)
{
	int minIndex = 0;
	int min = INT_MAX;
	const vector<int>& links = linkList[k];
	const vector<int>& weights = weightList[k];

	for (int i=0; i<links.size(); i++)
	{
		int index = links[i];

		if (distances[index] == INT_MAX)
			distances[index] = weights[i];

		if (visit[index] == false && distances[index] < min)
		{
			min = distances[index];
			minIndex = i;
		}
	}

	if (minIndex != 0)
	{
		weight += weights[minIndex];
		Explorer(minIndex, weight);
	}
}