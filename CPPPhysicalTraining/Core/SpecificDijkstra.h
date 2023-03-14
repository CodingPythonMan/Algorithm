#pragma once
class SpecificDijkstra
{
private:
	struct vertex {
		int index;
		int weight;
	};

	vector<vector<vertex>>	linkList;
	vector<bool>			visit;
	vector<int>				distances;
	
public:
	void					main();
	void					init(int n);
	void					dijkstra(const vertex& ver);
	int						explorer(int param1, int param2, int n);
};