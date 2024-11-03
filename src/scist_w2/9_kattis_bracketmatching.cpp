#include <bits/stdc++.h>

#define DEBUG

using namespace std;
int n;
stack<char> brackets;

int main()
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		char c = getchar();
		if (c == '(' || c == '[' || c == '{')
		{
			brackets.push(c);
			continue;
		}
		if (brackets.empty())
		{
			puts("Invalid");
			return 0;
		}
		char t = brackets.top();
		if ((
				t == '(' && c == ')') ||
			(t == '[' && c == ']') || (t == '{' && c == '}'))
		{
			brackets.pop();
		}
		else
		{
			puts("Invalid");
			return 0;
		}
	}
	if (!brackets.empty())
	{
		puts("Invalid");
		return 0;
	}
	puts("Valid");
	return 0;
}