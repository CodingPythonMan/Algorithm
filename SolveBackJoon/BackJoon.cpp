#include <iostream>
#include <cmath>
using namespace std;

int N, M, B;
int** Map;
double sum = 0;
int MapLength ;

int GetTime(int Aver)
{
	int TimeSum = 0;
	int differ;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] < Aver)
			{
				differ = Aver - Map[i][j];
				TimeSum += differ;
			}
			else if (Map[i][j] > Aver)
			{
				differ = Map[i][j] - Aver;
				TimeSum += (2 * differ);
			}
		}
	}
	
	return TimeSum;
}

int main()
{
	cin >> N >> M >> B;

	Map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		Map[i] = new int[M];
	}

	MapLength = M * N;
	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			Map[i][j] = num;
			sum += num;
		}
	}

	// 평균 낸 뒤 두 개 방향 조사.
	int Aver = (int)floor(sum / MapLength);
	int TimeSum = 0;
	int beforeTime = 0;
	int index = 0;

	TimeSum = GetTime(Aver);
	beforeTime = TimeSum;
	index++;
	while (sum + B >= (Aver+index) * MapLength)
	{
		TimeSum = GetTime(Aver + index);
		if (beforeTime < TimeSum)
		{
			TimeSum = beforeTime;
			break;
		}
		beforeTime = TimeSum;
		index++;
	}

	cout << TimeSum << " " << Aver + index - 1 << "\n";

	for (int i = 0; i < N; i++)
		delete[] Map[i];

	delete[] Map;
}