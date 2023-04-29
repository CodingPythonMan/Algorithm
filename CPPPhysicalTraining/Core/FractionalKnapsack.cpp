#include "pch.h"
#include "FractionalKnapsack.h"

struct BackPack
{
	int value;
	int weight;

	BackPack(int val, int wei) : value(val), weight(wei) {}
};

double FractionalKnapsack::solution(vector<vector<int>>& arr, int weight)
{
	double result = 0;
	vector<BackPack> backpacks;

	for (vector<int>& a : arr)
		backpacks.push_back({a[0],a[1]});

	auto cmp = [](BackPack& b1, BackPack& b2) {
		return b1.value < b2.value;
	};

	sort(backpacks.begin(), backpacks.end(), cmp);

	for (auto& backpack : backpacks)
	{
		if (backpack.weight < weight)
		{
			weight -= backpack.weight;
			result += backpack.value;
		}
		else if(backpack.weight == weight)
		{
			result += backpack.value;
			break;
		}
		else if(backpack.weight > weight)
		{
			result += (backpack.value*(static_cast<double>(weight) / static_cast<double>(backpack.weight)));
			break;
		}
	}

	return result;
}