#include <bits/stdc++.h>

using namespace std;

unsigned int a[100001];

int main()
{
	int n;
	unsigned long long asum = 0, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%u", a + i);
		asum += a[i];
	}
	scanf("%llu", &x);
	unsigned long long k = (x / asum) * (long long)n;
	x = x % asum;

	unsigned long long leftsum = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		leftsum += a[i];
		if (leftsum > x)
		{
			break;
		}
	}
	k += (unsigned long long)i + 1llu;

	printf("%llu\n", k);
	return 0;
}