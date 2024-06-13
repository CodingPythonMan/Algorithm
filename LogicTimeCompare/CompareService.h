#pragma once
#include <windows.h>
#include <string>
#include <vector>

// 프로파일러처럼 깔끔하게 데이터를 정리해도 된다.
// 서버를 시간당 분석하는 게 꽤 중요하다.
// 차근차근 해보자.

#define	TEST_COUNT		3
#define TESTCASE_COUNT	1000
#define COMPARE_COUNT	10000000

struct ProfileInfo
{
	LARGE_INTEGER	_startTime;	// 샘플 시작시간
	LARGE_INTEGER	_endTime;	// 샘플 종료시간
	
	std::wstring	_funcName;	// 함수 이름
	double			_cal;		// 계산 시간
};

struct Product 
{
	int _itemId;
	int _buyCount;
};

class CompareService
{
public:
	CompareService();
	virtual ~CompareService();

	void				Start();

protected:
	static unsigned int WINAPI CompareThread(LPVOID lpParam);
	static unsigned int WINAPI CompareThread2(LPVOID lpParam);
	static unsigned int WINAPI CompareThread3(LPVOID lpParam);

private:
	
	LARGE_INTEGER		_freq;

	ProfileInfo			_profiles[TEST_COUNT];

private:
	std::vector<int>	_itemIds;
	std::vector<int>	_buyCounts;
};