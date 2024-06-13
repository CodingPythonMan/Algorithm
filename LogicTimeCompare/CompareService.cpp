#include "CompareService.h"
#include <profileapi.h>
#include <process.h>
#include <iostream>
#include <map>
#include <unordered_map>

#pragma comment(lib, "winmm.lib")

CompareService::CompareService()
{
	timeBeginPeriod(1);
	QueryPerformanceFrequency(&_freq);
}

CompareService::~CompareService()
{
}

void CompareService::Start()
{
	for (int i = 0; i < COMPARE_COUNT; i++)
	{
		_itemIds.push_back(rand() % TESTCASE_COUNT);
		_buyCounts.push_back(rand() % TESTCASE_COUNT);
	}

	HANDLE handles[TEST_COUNT];
	// 핸들 관리 안하고, 그냥 스레드만 늘리는 식으로 해도 되겠다.
	handles[0] = (HANDLE)_beginthreadex(nullptr, 0, CompareThread3, this, 0, nullptr);
	handles[1] = (HANDLE)_beginthreadex(nullptr, 0, CompareThread2, this, 0, nullptr);
	handles[2] = (HANDLE)_beginthreadex(nullptr, 0, CompareThread, this, 0, nullptr);

	WaitForMultipleObjects(TEST_COUNT, handles, true, INFINITE);

	for (int i = 0; i < TEST_COUNT; i++)
	{
		std::wcout << "[" << _profiles[i]._funcName << "] : " << _profiles[i]._cal << "\n";
	}
}

unsigned int __stdcall CompareService::CompareThread(LPVOID lpParam)
{
	CompareService* service = (CompareService*)lpParam;
	std::map<int, int> compareMap;

	service->_profiles[0]._funcName = L"Map";

	QueryPerformanceCounter(&service->_profiles[0]._startTime);
	for (int i = 0; i < COMPARE_COUNT; i++)
	{
		auto it = compareMap.find(service->_itemIds[i]);
		if (it == compareMap.end())
			compareMap.insert({ service->_itemIds[i], service->_buyCounts[i] });
		else
			it->second += service->_buyCounts[i];
	}
	QueryPerformanceCounter(&service->_profiles[0]._endTime);

	service->_profiles[0]._cal = 
		(service->_profiles[0]._endTime.QuadPart - service->_profiles[0]._startTime.QuadPart)
		/ (double)(service->_freq.QuadPart);

	return 0;
}

unsigned int __stdcall CompareService::CompareThread2(LPVOID lpParam)
{
	CompareService* service = (CompareService*)lpParam;
	std::unordered_map<int, int> compareUnorderedMap;

	service->_profiles[1]._funcName = L"Unordered Map";

	QueryPerformanceCounter(&service->_profiles[1]._startTime);
	for (int i = 0; i < COMPARE_COUNT; i++)
	{
		auto it = compareUnorderedMap.find(service->_itemIds[i]);
		if (it == compareUnorderedMap.end())
			compareUnorderedMap.insert({ service->_itemIds[i], service->_buyCounts[i] });
		else
			it->second += service->_buyCounts[i];
	}
	QueryPerformanceCounter(&service->_profiles[1]._endTime);

	service->_profiles[1]._cal = (service->_profiles[1]._endTime.QuadPart - service->_profiles[1]._startTime.QuadPart)
		/ (double)(service->_freq.QuadPart);

	return 0;
}

unsigned int __stdcall CompareService::CompareThread3(LPVOID lpParam)
{
	CompareService* service = (CompareService*)lpParam;
	std::vector<Product> productVectors;

	service->_profiles[2]._funcName = L"Vector";

	QueryPerformanceCounter(&service->_profiles[2]._startTime);
	for (int i = 0; i < COMPARE_COUNT; i++)
	{
		bool check = false;
		for (int j = 0; j < productVectors.size(); j++)
		{
			if (productVectors[j]._itemId == service->_itemIds[i])
			{
				check = true;
				productVectors[j]._buyCount += service->_buyCounts[i];
				break;
			}
		}

		if (check == false)
			productVectors.push_back({ service->_itemIds[i], service->_buyCounts[i] });
	}
	QueryPerformanceCounter(&service->_profiles[2]._endTime);

	service->_profiles[2]._cal = (service->_profiles[2]._endTime.QuadPart - service->_profiles[2]._startTime.QuadPart)
		/ (double)(service->_freq.QuadPart);

	return 0;
}