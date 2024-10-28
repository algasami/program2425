#include <bits/stdc++.h>

using namespace std;
int n;
int a[1000000];
unsigned long long prefix_sqr_sum[1000001], suffix_sum[1000001];

int main()
{
	scanf("%d", &n);
	prefix_sqr_sum[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		a[i] = val;
		prefix_sqr_sum[i + 1] = (unsigned long long)val * (unsigned long long)val + prefix_sqr_sum[i];
	}
	suffix_sum[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		suffix_sum[i] = suffix_sum[i + 1] + a[i];
	}

	unsigned long long maxsum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		unsigned long long val = prefix_sqr_sum[i + 1] * suffix_sum[i + 1];
		if (val > maxsum)
		{
			maxsum = val;
		}
	}
	printf("%llu\n", maxsum);
	// 1 2 3
	// 0 1 5 14
	// 6 5 3 0
	return 0;
}