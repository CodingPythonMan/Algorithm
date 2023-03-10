#include "pch.h"
#include "DelayNetwork.h"

int DelayNetwork::networkDelayTime(vector<vector<int>>& times, int n, int k) {
	visit.resize(n + 1);
	linkList.resize(n + 1);
	weightList.resize(n + 1);

	for (const vector<int>& i : times)
	{
		linkList[i[0]].push_back(i[1]);
		weightList[i[0]].push_back(i[2]);
	}

	visit[k] = true;
	Explorer(linkList[k], weightList[k], 0);

	for (int i=1; i <visit.size() ; i++)
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
	for (int i=0; i<links.size(); i++)
	{
		int index = links[i];
		visit[index] = true;
		
		if (max < weight + weights[i])
			max = weight + weights[i];

		if (linkList[index].empty() == false)
		{
			weight += weights[i];
			Explorer(linkList[index], weightList[index], weight);
		}
	}
}