#include "CorePch.h"
#include "FractionalKnapsack.h"

int main()
{
	vector<vector<int>> arr;

	arr.push_back({60, 10});
	arr.push_back({100, 20});
	arr.push_back({120, 30});

	int weight = 50;

	FractionalKnapsack f;
	cout << f.solution(arr, weight);
}