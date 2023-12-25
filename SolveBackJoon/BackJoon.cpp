#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos {
	int X;
	int Y;
	int Rank;
};

int main()
{
	int n;
	cin >> n;

	vector<Pos> Infos;
	for (int i = 0; i < n; i++)
	{
		Pos Info;
		Info.Rank = 1;
		cin >> Info.X >> Info.Y;
		Infos.push_back(Info);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Infos[i].X > Infos[j].X && Infos[i].Y > Infos[j].Y)
			{
				Infos[j].Rank++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << Infos[i].Rank << " ";
	}
}