#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<char> Stack;
	bool answer;

	while (1)
	{
		answer = true;
		string line;
		getline(cin, line);

		if (line[0] == '.')
			break;
		
		for(int i=0; line[i] != '.'; i++)
		{
			if (line[i] == ']' || line[i] == ')')
			{
				if (Stack.size() == 0)
				{
					answer = false;
					break;
				}
				else
				{
					char Pop = Stack.top();
					if (line[i] == ']' && Pop != '['
					|| line[i] == ')' && Pop != '(')
					{
						answer = false;
						break;
					}
					Stack.pop();
					continue;
				}
			}

			if (line[i] == '(' || line[i] == '[')
				Stack.push(line[i]);
		}

		if (Stack.size() > 0)
			answer = false;

		if(answer == true)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
			
		while (false == Stack.empty()) 
			Stack.pop();
	}
}