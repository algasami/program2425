#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long n;
	scanf("%llu", &n);
	unsigned long long i = 1;
	while (i * (i + 1) * (i + 2) < n)
		i++;
	printf("%llu\n", i - 1);
	return 0;
}