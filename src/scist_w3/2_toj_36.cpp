#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long a, b, c;
	scanf("%llu %llu %llu", &a, &b, &c);
	unsigned long long base = 1;
	while (b)
	{
		if (b & 1)
		{
			base = (base * a) % c;
		}
		a = (a * a) % c;
		b >>= 1;
	}
	printf("%llu\n", base);
	return 0;
}