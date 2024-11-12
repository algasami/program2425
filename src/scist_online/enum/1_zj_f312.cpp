#include <bits/stdc++.h>

using namespace std;

int n;
long long a1, b1, c1, a2, b2, c2;

long long profit(int x1)
{
	int x2 = n - x1;
	return a1 * x1 * x1 + b1 * x1 + c1 +
		   a2 * x2 * x2 + b2 * x2 + c2;
}

int main()
{
	scanf("%lld %lld %lld", &a1, &b1, &c1);
	scanf("%lld %lld %lld", &a2, &b2, &c2);
	scanf("%d", &n);
	long long biggest = LLONG_MIN;
	for (int x1 = 0; x1 <= n; x1++)
	{
		long long pro = profit(x1);
		if (pro > biggest)
		{
			biggest = pro;
		}
	}
	printf("%lld\n", biggest);
	return 0;
}