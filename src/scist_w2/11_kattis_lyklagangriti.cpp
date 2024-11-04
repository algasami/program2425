#include <bits/stdc++.h>

using namespace std;

// this question wants you to use std::list

list<char> buffer;

int main()
{
	char c;
	auto iter = buffer.end();
	while ((c = getchar()) != '\n')
	{
		if (c == 'R')
		{
			iter = next(iter);
			continue;
		}
		else if (c == 'L')
		{
			iter = prev(iter);
			continue;
		}
		else if (c == 'B')
		{
			buffer.erase(prev(iter));
			continue;
		}
		buffer.insert(iter, c);
	}
	for (char c : buffer)
	{
		putchar(c);
	}
	putchar('\n');
	return 0;
}