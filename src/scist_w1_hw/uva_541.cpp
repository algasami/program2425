#include <bits/stdc++.h>

using namespace std;

int solve()
{
	int rowsum[101] = {0}, colsum[101] = {0}, n;
	// rowsum[row], colsum[col]
	int cbi = -1, cbj = -1;
	scanf("%d", &n);
	if (!n)
	{
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int val;
			scanf("%d", &val);
			if (val)
			{
				rowsum[i] = (rowsum[i] + 1) & 1;
				colsum[j] = (colsum[j] + 1) & 1;
			}
		}
	}

	// about n^2, but since the nested loop
	// at most executes once, it's around n
	// so linear time! :) O(n)

	for (int i = 0; i < n; i++)
	{
		if (rowsum[i])
		{
			if (cbi >= 0)
			{
				puts("Corrupt");
				return 0;
			}
			// try to change
			for (int j = 0; j < n; j++)
			{
				if (colsum[j])
				{
					rowsum[i]--;
					colsum[j]--;
					cbi = i;
					cbj = j;
				}
			}
			// no ops
			if (cbi < 0)
			{
				puts("Corrupt");
				return 0;
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (colsum[j])
		{
			if (cbi >= 0)
			{
				puts("Corrupt");
				return 0;
			}
			// try to change
			for (int i = 0; i < n; i++)
			{
				if (rowsum[i])
				{
					rowsum[i]--;
					colsum[j]--;
					cbi = i;
					cbj = j;
				}
			}
			if (cbi < 0)
			{
				puts("Corrupt");
				return 0;
			}
		}
	}

	if (cbi >= 0)
	{
		printf("Change bit (%d,%d)\n", cbi + 1, cbj + 1);
		return 0;
	}
	puts("OK");

	return 0;
}

int main()
{
	while (!solve())
		;

	return 0;
}