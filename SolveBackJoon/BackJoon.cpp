#include <iostream>
#include <algorithm>
using namespace std;

struct Pos {
public:
	int _x;
	int _y;
};

/*
void SwapPos(Pos& pos1, Pos& pos2)
{
	Pos pos = pos1;
	pos1 = pos2;
	pos2 = pos;
}

bool ComparePos(const Pos& pos1, const Pos& pos2)
{
	if (pos1._x < pos2._x)
		return true;
	else if (pos1._x == pos2._x)
	{
		return pos1._y < pos2._y;
	}
	else
		return false;
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
		if (ComparePos(posArray[j], pivot))
		{
			SwapPos(posArray[i], posArray[j]);
			i++;
		}
	}
	SwapPos(posArray[i], pivot);
	
	QuickSort(posArray, left, i-1);
	QuickSort(posArray, i+1, right);
}*/

int main()
{
	int n;
	cin >> n;

	Pos* posArray = new Pos[n];

	for (int i = 0; i < n; i++)
	{
		cin >> posArray[i]._x >> posArray[i]._y;
	}

	//QuickSort(posArray, 0, n - 1);

	sort(posArray, posArray + n, [](const Pos& pos1, const Pos& pos2)
	{
		if (pos1._x < pos2._x)
			return true;
		else if (pos1._x == pos2._x)
		{
			return pos1._y < pos2._y;
		}
		else
			return false;
	});

	for (int i = 0; i < n; i++)
		cout << posArray[i]._x << " " << posArray[i]._y << "\n";
}