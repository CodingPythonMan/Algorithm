#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	int five = n / 5;
	int tfive = n / 25;
	int hfive = n / 125;

	cout << five + tfive + hfive;
}