#include "pch.h"
#include <cstdlib>
#include <ctime>
//#include <algorithm>

void Print(const vector<int>& arr)
{
	for (int i : arr)
	{
		cout << i << ", ";
	}
}

int main()
{
	// 백준 필요 cin
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	vector<vector<int>> times;
	int n = 4;
	int k = 2;

	times.push_back({2,1,1});
	times.push_back({2,3,1});
	times.push_back({3,4,1});

	DelayNetwork d;
	cout << d.networkDelayTime(times, n, k) << endl;
	//times = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
}