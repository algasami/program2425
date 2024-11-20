#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long c = a % b;
	if (c > b >> 1)
	{
		c = b - c;
	}
	printf("%lld\n", c);
	return 0;
}