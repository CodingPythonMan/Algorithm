#include <climits>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<long> distances;
vector<int> visibles;
vector<vector<pair<int, long>>> linkList;

int main()
{
	int n, e;
	cin >> n >> e;

	distances.resize(n);
	visibles.resize(n);

	for (int i = 1; i < n; i++)
		distances[i] = LONG_MAX;

	for (int i = 0; i < n; i++)
	{
		cin >> visibles[i];
	}
	
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		linkList[a].push_back({ b,c });
		linkList[b].push_back({ a,c });
	}

}