#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	char** route = new char*[n];
	for (int i = 0; i < n; i++)
	{
		route[i] = new char[n];
	}

	int Start, End;
	for (int i = 0; i < m; i++)
	{
		cin >> Start >> End;
		route[Start - 1][End - 1] = 1;

		
	}
	
	// 어떻게 구해볼까?
	// 최소 거리를 어떻게 구하지? 
}