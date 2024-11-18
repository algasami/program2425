#include <bits/stdc++.h>

using namespace std;

int n, D, c, pn, sum = 0;
int a[100];

int main()
{
	scanf("%d %d", &n, &D);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	c = a[0];
	for (int i = 0; i < n; i++)
	{
		if (c && a[i] - c >= D)
		{
			sum += a[i] - c;
			pn = a[i];
			c = 0;
		}
		if (!c && a[i] <= pn - D)
		{
			c = a[i];
		}
	}
	printf("%d\n", sum);
	return 0;
}