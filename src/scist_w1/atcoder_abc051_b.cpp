#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
	int K, S;
	scanf("%d %d", &K, &S);
	// X + Y + Z = S
	// 0 <= X, Y, Z <= K
	int amount = 0;
	for (int x = 0; x <= K; x++)
	{
		for (int y = 0; y <= min(S - x, K); y++)
		{
			int z = S - x - y;
			if (0 <= z && z <= K)
				++amount;
		}
	}
	printf("%d\n", amount);
	return 0;
}