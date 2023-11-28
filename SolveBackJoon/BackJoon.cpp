#include <iostream>
using namespace std;

struct Pos {
public:
	int _x;
	int _y;
};

void SwapPos(Pos& pos1, Pos& pos2)
{
	Pos pos = pos1;
	pos1 = pos2;
	pos2 = pos;
}

int ComparePos(const Pos& pos1, const Pos& pos2)
{
	if (pos1._x < pos2._x)
		return 1;
	else if (pos1._x == pos2._x)
	{
		if (pos1._y < pos2._y)
			return 1;
		else if (pos1._y == pos2._y)
			return 0;
		else
			return -1;
	}
	else
		return -1;
}

void QuickSort(Pos* posArray, int left, int right)
{
	if (left >= right)
		return;

	int i, j;
	i = left;
	j = left;

	Pos& pivot = posArray[right];
	for (; j < right; j++)
	{
		if (1 == ComparePos(posArray[j], pivot))
		{
			SwapPos(posArray[i], posArray[j]);
			i++;
		}
	}
	SwapPos(posArray[i], pivot);
	
	QuickSort(posArray, left, i-1);
	QuickSort(posArray, i+1, right);
}

int main()
{
	int n;
	cin >> n;

	Pos* posArray = new Pos[n];

	for (int i = 0; i < n; i++)
	{
		cin >> posArray[i]._x >> posArray[i]._y;
	}

	QuickSort(posArray, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << posArray[i]._x << " " << posArray[i]._y << "\n";
}