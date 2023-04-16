#include "pch.h"
#include "TakeJellys.h"

int TakeJellys::solution(vector<string> pouches) {
	int answer = 0;

	// 우선 젤리를 싹 가지고 있다가, 하나씩 빼는걸로 할까?
	vector<int> jellys;
	jellys.resize(5);

	for (string str : pouches)
	{
		for (int i = 0; i < str.length(); i++)
			jellys[str.at(i) - 'a'] ++;
	}

	return answer;
}