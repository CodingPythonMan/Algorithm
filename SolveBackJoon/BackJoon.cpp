#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, M, B;
	cin >> N >> M >> B;

	int** Map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		Map[i] = new int[M];
	}

	double sum = 0;
	int MapLength = M * N;
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
	double Aver = floor(sum / MapLength);
	int BeforeTimeSum = 0;
	int TimeSum;
	int Block;
	while (1)
	{
		TimeSum = 0;
		Block = B;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Map[i][j] < Aver)
				{

				}
				else if (Map[i][j] > Aver)
				{

				}
			}
		}

		Aver--;
	}

	for (int i = 0; i < N; i++)
		delete[] Map[i];

	delete[] Map;
}