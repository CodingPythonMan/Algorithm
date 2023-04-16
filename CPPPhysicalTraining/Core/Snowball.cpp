#include "pch.h"
#include "Snowball.h"

vector<int> Snowball::solution(vector<int>& snowballs)
{
	vector<int> result;
	stack<int> store;

	for (int snowball : snowballs)
	{
		int temp;

		if (snowball < 0)
		{
			bool bDead = false;
			while (store.size() > 0)
			{
				temp = store.top();

				if (-snowball > temp)
				{
					store.pop();
				}
				else if (-snowball == temp)
				{
					store.pop();
					bDead = true;
					break;
				}
				else
				{
					bDead = true;
					break;
				}
			}

			if (bDead == false && store.size() == 0)
			{
				result.push_back(snowball);
			}
		}
		else if (snowball > 0)
		{
			store.push(snowball);
		}
	}

	stack<int> tempStack;
	while (false == store.empty())
	{
		tempStack.push(store.top());
		store.pop();
	}

	while (false == tempStack.empty())
	{
		result.push_back(tempStack.top());
		tempStack.pop();
	}

	return result;
}