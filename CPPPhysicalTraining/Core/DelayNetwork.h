#pragma once
class DelayNetwork
{
public:
	vector<bool> visit;
	vector<vector<int>> linkList;
	vector<vector<int>> weightList;
	vector<int> distances;

	int networkDelayTime(vector<vector<int>>& times, int n, int k);
	void Explorer(const int start, int weight);
};