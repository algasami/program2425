#include <bits/stdc++.h>

using namespace std;

/*
N
indicates a move to the previous row,
S
indicates a move to the next row,
W
indicates a move to the previous column,
E
indicates a move to the next column, and
T
indicates the location of the treasure.
*/

int r, c;
char action_map[201][201], visited[201][201] = {0};
// Deterministic Stateless Model. Visited = true then in cycle

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char val;
			scanf(" %c", &val);
			action_map[i][j] = val;
		}
	}

	int ci = 0, cj = 0, moves = 0;

	while (1)
	{
		if (ci < 0 || ci >= r || cj < 0 || cj >= c)
		{
			puts("Out");
			return 0;
		}
		if (visited[ci][cj])
		{
			break;
		}
		visited[ci][cj] = 1;
		switch (action_map[ci][cj])
		{
		case 'N':
			ci--;
			break;
		case 'S':
			ci++;
			break;
		case 'W':
			cj--;
			break;
		case 'E':
			cj++;
			break;
		case 'T':
			printf("%d\n", moves);
			return 0;
		}
		moves++;
	}
	puts("Lost");

	return 0;
}