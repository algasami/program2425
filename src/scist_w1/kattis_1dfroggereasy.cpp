#include <bits/stdc++.h>

int n, s, m, h = 0;
int squares[201], visited[201] = {0};

int main()
{
	scanf("%d %d %d", &n, &s, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", squares + i);
	}
	s--;
	while (1)
	{
		if (s < 0)
		{
			puts("left");
			break;
		}
		else if (s >= n)
		{
			puts("right");
			break;
		}
		else if (visited[s])
		{
			puts("cycle");
			break;
		}
		else if (squares[s] == m)
		{
			puts("magic");
			break;
		}
		visited[s] = 1;
		// hops
		s = s + squares[s];
		h++;
	}
	printf("%d\n", h);
	return 0;
}