#include <bits/stdc++.h>

using namespace std;

int solve()
{
	int n;
	scanf("%d", &n);
	if (!n)
	{
		return 1;
	}
	while (1)
	{
		stack<int> station;
		int permute[1001], j = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", permute + i);
			if (!permute[i])
			{
				putchar('\n');
				return 0;
			}
		}
		for (int current_front = 1; current_front <= n; current_front++)
		{
			/*
			As long as the top of the station matches our cursor at permute, we keep popping (since that's how
			the station works) until it doesn't match, then we aggregate.
			*/
			station.push(current_front);
			while (!station.empty() && station.top() == permute[j])
			{
				station.pop();
				j++;
			}
		}
		if (station.empty())
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

int main()
{
	while (!solve())
		;
	return 0;
}