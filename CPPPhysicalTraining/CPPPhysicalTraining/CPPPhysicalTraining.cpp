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
	linkList.resize(n);

	for (int i = 1; i < n; i++)
		distances[i] = LONG_MAX;

	for (int i = 0; i < n; i++)
		cin >> visibles[i];
	
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		linkList[a].push_back({ b,c });
		linkList[b].push_back({ a,c });
	}

	auto cmp = [](const pair<int, long>& p1, const pair<int, long>& p2) {
		return (p1.second > p2.second);
	};

	priority_queue<pair<int, long>, vector<pair<int, long>>, decltype(cmp)> pq(cmp);

	//  Q �� G�� ��� �������� �ִ´�.
	while (pq.size() != 0)
	{
		const pair<int, long>& node = pq.top();
		pq.pop();

		// node �� ���� ���� ���� ����
	}
}