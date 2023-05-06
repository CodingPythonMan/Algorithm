#include "CorePch.h"
#include "FractionalKnapsack.h"

int main()
{
	vector<vector<int>> arr;

	arr.push_back({500, 30});

	int weight = 10;

	FractionalKnapsack f;
	cout << f.solution(arr, weight);
}