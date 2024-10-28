#include <bits/stdc++.h>

using namespace std;

int n;
int main()
{
	unsigned long long product = 1ll;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		unsigned long long sum = 0ll;
		for (int j = 0; j < 6; j++)
		{
			int val;
			scanf("%d", &val);
			sum += val;
		}
		product = (product * sum) % 1000000007ll;
	}
	// a1 a2 a3
	// b1 b2 b3
	// total = a1 * (b1 + b2 + b3) + a2 * (b1 + b2 + b3) + a3 * (b1 + b2 + b3)
	// total = (a1 + a2 + a3) * (b1 + b2 + b3)
	// we can expand this
	// total = (ra1 + ra2 + ... + ra6) * (rb1 + rb2 + ... + rb6) ...
	printf("%llu\n", product);
	return 0;
}