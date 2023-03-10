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
	int n = 3;
	int k = 1;

	// 기존 알고리즘으로 틀린 부분.
	times.push_back({1,2,1});
	times.push_back({2,3,2});
	times.push_back({1,3,2});

	DelayNetwork d;
	cout << d.networkDelayTime(times, n, k) << endl;
}