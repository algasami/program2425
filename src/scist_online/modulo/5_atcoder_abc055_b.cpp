#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long fact = 1;
	int n;
	scanf("%d", &n);
	do
	{
		fact = fact * n % 1000000007ULL;
	} while (--n);
	printf("%llu\n", fact);
	return 0;
}