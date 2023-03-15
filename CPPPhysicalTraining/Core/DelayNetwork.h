#pragma once
class DelayNetwork
{
public:
	vector<vector<pair<int, int>>> graph;
	vector<int> distances;

	int networkDelayTime(vector<vector<int>>& times, int n, int k);
	void Explorer(int start);
};