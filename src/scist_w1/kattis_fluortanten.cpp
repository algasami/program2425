#include <bits/stdc++.h>

#define MAXSIZE 1000001
#define DEBUG

using namespace std;

// suffix sum: opposite of prefix sum!
// use long long to prevent accidental overflow >:(
long long int suffix_sum[MAXSIZE + 1], weight[MAXSIZE];
int main()
{
	int n;
	long long int weightsum = 0, realsum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", weight + i);
		if (weight[i] == 0)
		{
			n--;
			i--;
			continue;
		}
		weightsum += weight[i];
		realsum += (i + 1) * weight[i];
	}
	suffix_sum[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		suffix_sum[i] = suffix_sum[i + 1] + weight[i];
	}

	long long int max_weight_delt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (suffix_sum[i] > max_weight_delt)
		{
			max_weight_delt = suffix_sum[i];
		}
	}
	printf("%lld\n", max_weight_delt + realsum);
	return 0;
}