#include <bits/stdc++.h>
using namespace std;
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2521

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		long long num = 0, sqrtn = sqrt(n);
		for (int k = 1; k <= sqrtn; k++)
		// ^ Do not use k*k, extremely slow! Rather, cache the result of the square root and compare it on live.
		{
			int current = n / k;
			int next = n / (k + 1);
			num += current;
			if (current != k)
			{
				num += (current - next) * k;
			}
		}
		printf("%lld\n", num);
	}
	return 0;
}