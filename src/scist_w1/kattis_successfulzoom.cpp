#include <bits/stdc++.h>

using namespace std;

int n;
int x[100001]; // 1-based here

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", x + i);
	}
	int half = n >> 1;
	// around o(n^2) so approx. 10^10 * (1/2) around 1 second (less than)
	for (int k = 1; k <= half; k++)
	{
		int elems = n / k, bad = 0;
		for (int q = 2; q <= elems; q++)
		{
			if (x[q * k] - x[(q - 1) * k] <= 0)
			{
				bad = 1;
				break;
			}
		}
		if (!bad)
		{
			printf("%d\n", k);
			return 0;
		}
	}
	puts("ABORT!");
	return 0;
}