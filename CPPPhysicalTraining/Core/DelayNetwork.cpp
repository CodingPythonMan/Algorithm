#include "pch.h"
#include "DelayNetwork.h"

int DelayNetwork::networkDelayTime(vector<vector<int>>& times, int n, int k) {
	for (int i = 0; i < n; i++)
		visit.push_back(false);

	linkList.resize(n);
	weightList.resize(n);

	for (const vector<int>& i : times)
	{
		linkList[i[0]].push_back(i[2]);
		weightList[i[0]].push_back(i[3]);
	}

	Explorer(linkList[k], weightList[k], 0);

	for (int i : visit)
	{
		if (visit[i] == false)
		{
			max = -1;
			break;
		}
	}

	return max;
}

void DelayNetwork::Explorer(const vector<int>& links, const vector<int>& weights, int weight)
{
	if (max < weight)
		max = weight;

	for (int i : links)
	{
		if (linkList[i].empty() == false)
		{
			weight += weights[i];
			Explorer(linkList[i], weightList[i], weight);
		}
	}
}