#include <bits/stdc++.h>
using namespace std;

int solve(int x)
{
	int absx = abs(x);
	int neg = x < 0;
	for (int p = 31; p >= 1; p--)
	{
		if (neg && p % 2 == 0)
		{
			continue;
		}
		int b = (int)(pow((double)absx, 1.0 / (double)p) + 0.1);
		int mx = (int)(pow((double)b, (double)p) + 0.1);
		// do not use abs(round(f) - f). very unsafe. use
		// inverse function instead.
		// find b, then find mx original
		// + 0.1 to avoid 2.999... 3.00001
		if (mx == absx)
		{
			return p;
		}
	}
	return 1;
}

int main()
{
	while (true)
	{
		int x;
		scanf("%d", &x);
		if (!x)
		{
			break;
		}
		printf("%d\n", solve(x));
	}
	return 0;
}
