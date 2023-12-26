#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos {
	int X;
	int Y;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<Pos> arr;
	for (int i = 0; i < n; i++)
	{
		Pos pos;
		cin >> pos.X >> pos.Y;
		arr.push_back(pos);
	}

	sort(arr.begin(), arr.end(), [](const Pos& o1, const Pos& o2) {
		if (o1.Y == o2.Y)
		{
			return o1.X < o2.X;
		}
		return o1.Y < o2.Y;
	});

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].X << " " << arr[i].Y << "\n";
	}
}