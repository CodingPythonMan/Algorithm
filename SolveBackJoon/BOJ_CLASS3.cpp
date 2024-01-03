#include "BOJ_CLASS3.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BOJ1463_1()
{
	int n;
	cin >> n;
	vector<int> dp(n + 1);

	//bottom-up
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == false)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == false)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n] << endl;
}