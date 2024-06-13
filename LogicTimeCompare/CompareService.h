#pragma once
#include <windows.h>
#include <string>
#include <vector>

// �������Ϸ�ó�� ����ϰ� �����͸� �����ص� �ȴ�.
// ������ �ð��� �м��ϴ� �� �� �߿��ϴ�.
// �������� �غ���.

#define	TEST_COUNT		3
#define TESTCASE_COUNT	1000
#define COMPARE_COUNT	10000000

struct ProfileInfo
{
	LARGE_INTEGER	_startTime;	// ���� ���۽ð�
	LARGE_INTEGER	_endTime;	// ���� ����ð�
	
	std::wstring	_funcName;	// �Լ� �̸�
	double			_cal;		// ��� �ð�
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