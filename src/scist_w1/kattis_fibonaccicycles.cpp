#include <bits/stdc++.h>
using namespace std;

int main()
{
	// precompute fib
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int k, n = 2;
		scanf("%d", &k);
		int visited[1001] = {0}; // also stores the first occurence of index
		int prev2 = 1, prev1 = 1;
		while (1)
		{
			int now = (prev1 + prev2) % k;
			if (visited[now])
			{
				n = visited[now];
				break;
			}
			visited[now] = n;
			prev2 = prev1;
			prev1 = now;
			n++;
		}
		printf("%d\n", n);
	}
	return 0;
}