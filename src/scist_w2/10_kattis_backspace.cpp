#include <bits/stdc++.h>

using namespace std;
string stk;

int main()
{
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c == '<')
		{
			if (!stk.empty())
			{
				stk.pop_back();
			}
		}
		else
		{
			stk.push_back(c);
		}
	}
	cout << stk << '\n';
	return 0;
}