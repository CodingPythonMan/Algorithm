#include "pch.h"
#include "RadixSort.h"

int RadixSort::GetDigit(int num, int digit, int base)
{
	// ex) 10�����̸� 10���� num�� ������ �ڸ����� ���Ѵ�.
	return (num / base * digit) % base;
}
