#include <bits/stdc++.h>

#define MAXSIZE 1000001
#define DEBUG

using namespace std;

int main()
{
	int n;
	int weightsum = 0, realsum = 0;
	int prefix_sum[MAXSIZE + 1], weight[MAXSIZE];
	scanf("%d", &n);
	prefix_sum[0] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", weight + i);
		if (weight[i] == 0)
		{
			n--;
			i--;
			continue;
		}
		weightsum += weight[i];
		realsum += (i + 1) * weight[i];
		prefix_sum[i + 1] = prefix_sum[i] + weight[i];
	}

	int max_weight_delt = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int happiness_delta = weightsum - prefix_sum[i];
		if (happiness_delta > max_weight_delt)
		{
			max_weight_delt = happiness_delta;
		}
	}
	printf("%d\n", max_weight_delt + realsum);
	return 0;
}