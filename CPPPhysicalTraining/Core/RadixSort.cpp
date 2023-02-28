#include "pch.h"
#include "RadixSort.h"

int RadixSort::GetDigit(int num, int digit, int base)
{
	// ex) 10진법이면 10으로 num을 나누고 자릿수를 곱한다.
	return (num / base * digit) % base;
}
