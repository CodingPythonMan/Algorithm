#include "pch.h"
#include "TakeJellys.h"

int TakeJellys::solution(vector<string> pouches) {
	int answer = 0;

	// �켱 ������ �� ������ �ִٰ�, �ϳ��� ���°ɷ� �ұ�?
	vector<int> jellys;
	jellys.resize(5);

	for (string str : pouches)
	{
		for (int i = 0; i < str.length(); i++)
			jellys[str.at(i) - 'a'] ++;
	}

	return answer;
}