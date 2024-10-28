#include <bits/stdc++.h>

using namespace std;

int n, mat[21][21];

// assume ti >= i, tj >= j
// this is O(n^2)
int addup(int i, int j, int ti, int tj)
{
	int sum = 0;
	for (int y = i; y <= ti; y++)
	{
		for (int x = j; x <= tj; x++)
		{
			sum += mat[y][x];
		}
	}
	return sum;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	// small n (1 <= n <= 20)
	// we can do an O(n^6) bruteforce
	// around 0.8 seconds (still AC)
	int best = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int acci = i; acci < n; acci++)
			{
				for (int accj = j; accj < n; accj++)
				{
					int val = addup(i, j, acci, accj);
					if (val > best)
					{
						best = val;
					}
				}
			}
		}
	}
	printf("%d\n", best);
	return 0;
}