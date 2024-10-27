#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

int n, m, r, c;
int target[101][101], canva[101][101];
unsigned long int ops;
void negate_canva(int tly, int tlx)
{
	for (int i = tly; i < tly + r; i++)
	{
		for (int j = tlx; j < tlx + c; j++)
		{
			canva[i][j] = !canva[i][j];
		}
	}
	ops++;
}

int solve()
{
	ops = 0;
	scanf("%d %d %d %d", &n, &m, &r, &c);
	if (n == 0)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			scanf(" %c", &c);
			target[i][j] = c - '0';
			canva[i][j] = 0;
		}
	}
#ifdef DEBUG
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			putchar(target[i][j] + '0');
		}
		putchar('\n');
	}
#endif
	for (int i = 0; i < n - r + 1; i++)
	{
		for (int j = 0; j < m - c + 1; j++)
		{
			if (canva[i][j] != target[i][j])
			{
				negate_canva(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (canva[i][j] != target[i][j])
			{
				puts("-1");
				return 1;
			}
		}
	}
	printf("%llu\n", ops);
	return 1;
}

int main()
{
	while (solve())
		;
	return 0;
}
