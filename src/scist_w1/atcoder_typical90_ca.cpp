#include <bits/stdc++.h>

using namespace std;

long int a[101][101], b[101][101];
int h, w;
long int ops = 0; // prevents overflow
void opdelta(int y, int x, long int offset)
{
	a[y][x] += offset;
	a[y + 1][x] += offset;
	a[y][x + 1] += offset;
	a[y + 1][x + 1] += offset;
	ops += abs(offset);
}
int main()
{
	scanf("%d %d\n", &h, &w);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			scanf("%lld", &b[i][j]);
		}
	}
	// only focus on the top left corner. op +1 and op -1 negate each other.
	// so operation should only be done on each control point once,
	// or it's meaningless to do so.
	for (int i = 0; i < h - 1; i++)
	{
		for (int j = 0; j < w - 1; j++)
		{
			if (a[i][j] != b[i][j])
			{
				opdelta(i, j, b[i][j] - a[i][j]);
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] != b[i][j])
			{
				puts("No");
				return 0;
			}
		}
	}
	printf("Yes\n%lld\n", ops);
	return 0;
}