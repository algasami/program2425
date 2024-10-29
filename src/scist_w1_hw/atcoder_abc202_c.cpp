#include <bits/stdc++.h>

using namespace std;

#define SIZE 100001

int n; // max 10^5
int ahash[SIZE] = {0}, b[SIZE], c[SIZE];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		ahash[val]++;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", b + i);
	}
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		c[i] = val - 1; // switch to zero-based
	}
	unsigned long long pairs = 0ll;
	for (int j = 0; j < n; j++)
	{
		pairs += (unsigned long long)ahash[b[c[j]]];
	}
	printf("%llu\n", pairs);

	// find all (i, j) a[i] = b[ c[j] ]
	// bruteforce: O(n^2) around 100 seconds
	// i = a^-1 [ b [ c [ j]]]
	// a^-1[k] = number of indices in a that has value k
	// so that number of indices should
	// reduces to o(n)

	return 0;
}