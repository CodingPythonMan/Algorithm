#include "pch.h"
#include "Delivery.h"

struct Info {
	int weight;
	int from;
	int to;
};

bool Delivery::solution(int capacity, vector<vector<int>> routes) {
	bool answer = true;

	vector<Info> infos;

	for (const vector<int>& route : routes)
	{
		infos.push_back({ route[0], route[1], route[2] });
	}

	auto cmp = [](const Info& info1, const Info& info2) {
		return info1.from < info2.from;
	};

	sort(infos.begin(), infos.end(), cmp);

	int presentWeight = 0;
	for (int i = 0; i < infos.size(); i++)
	{
		presentWeight += infos[i].weight;

		for (int j = 0; j < i; j++)
		{
			if (infos[j].to <= infos[i].from)
				presentWeight -= infos[j].weight;
		}

		if (presentWeight > capacity)
		{
			answer = false;
			break;
		}
	}

	return answer;
}