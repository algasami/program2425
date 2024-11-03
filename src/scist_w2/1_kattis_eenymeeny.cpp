#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
int n, z = 0, remaining[101];
int chosens[101][101];
int team_len[101];
char name[101][101];

int main()
{
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c == ' ')
		{
			z++;
		}
	}
	z++;

#ifdef DEBUG
	printf("%d\n", z);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
		remaining[i] = 1;
	}
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		int j = -1, q = 0;
		while (q < z)
		{
			j++;
			if (remaining[(start + j) % n] == 0)
			{
				continue;
			}
			q++;
		}
		int ci = (start + j) % n;
		remaining[ci] = 0;
		chosens[i % 2][team_len[i % 2]++] = ci;
#ifdef DEBUG
		printf("chose %d\n", ci);
#endif
		start = (ci + 1) % n;
	}
	for (int i = 0; i < 2; i++)
	{
		printf("%d\n", team_len[i]);
		for (int j = 0; j < team_len[i]; j++)
		{
			printf("%s\n", name[chosens[i][j]]);
		}
	}
	return 0;
}