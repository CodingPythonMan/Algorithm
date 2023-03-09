#pragma once
class DelayNetwork
{
public:
	vector<bool> visit;
	vector<vector<int>> linkList;
	vector<vector<int>> weightList;
	int max = 0;

	int networkDelayTime(vector<vector<int>>& times, int n, int k);
	void Explorer(const vector<int>& links, const vector<int>& weights, int weight);
};

