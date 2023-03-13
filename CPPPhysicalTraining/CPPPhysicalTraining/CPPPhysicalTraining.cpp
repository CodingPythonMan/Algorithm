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
	int n = 5;
	int k = 1;

	// 기존 알고리즘으로 틀린 부분.
	times.push_back({2,4,10});
	times.push_back({5,2,38});
	times.push_back({3,4,33});
	times.push_back({4,2,76});
	times.push_back({3,2,64});
	times.push_back({1,5,54});
	times.push_back({1,4,98});
	times.push_back({2,3,61});
	times.push_back({2,1,0});
	times.push_back({3,5,77});
	times.push_back({5,1,34});
	times.push_back({3,1,79});
	times.push_back({5,3,2});
	times.push_back({1,2,59});
	times.push_back({4,3,46});
	times.push_back({5,4,44});
	times.push_back({2,5,89});
	times.push_back({4,5,21});
	times.push_back({1,3,86});
	times.push_back({4,1,95});

	DelayNetwork d;
	cout << d.networkDelayTime(times, n, k) << endl;
}