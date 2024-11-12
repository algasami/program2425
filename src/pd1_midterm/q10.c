#include <stdio.h>
#include <stdlib.h>

/*
[10] (a) Write a recursive function f(int n, int m) that can print m^n combinations of v[1] v[2] … v[n],
where v[i] in {1, 2, …, m}. For example, if n = 2 and m = 3, the following number list is printed: 1
1, 1 2, 1 3, 2 1, 2 2, 2 3, 3 1, 3 2, 3 3
(b) Modify f(int n, int m) to print the combinations of v[1] v[2] … v[n], where v[i] in {1, 2, …, m}
and v[1] in v[2]...v[n]. So, if n = 2 and m = 3, the following number list is printed:
1 2, 1 3, 2 1, 2 3, 3 1, 3 2
*/

int *v, first = 1;
int N, M;

void f(int n, int m)
{
	if (n <= 0)
	{
		// finish building v
		if (!first)
		{
			printf(", ");
		}
		printf("%d", v[N - 1]);
		for (int i = N - 2; i >= 0; i--)
		{
			printf(" %d", v[i]);
		}
		first = 0;
		return;
	}
	for (int i = 0; i < m; i++)
	{
		v[n - 1] = i + 1;
		f(n - 1, m);
	}
}

int *visited;

void f_comb(int n, int m)
{
	if (n <= 0)
	{
		if (!first)
		{
			printf(", ");
		}
		printf("%d", v[N - 1]);
		for (int i = N - 2; i >= 0; i--)
		{
			printf(" %d", v[i]);
		}
		first = 0;
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (visited[i])
		{
			continue;
		}
		// choose i
		visited[i] = 1;
		v[n - 1] = i + 1;
		f_comb(n - 1, m);
		visited[i] = 0;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	v = (int *)calloc(N, sizeof(int));
	visited = (int *)calloc(N, sizeof(int));
	f(N, M);
	putchar('\n');
	first = 1;
	f_comb(N, M);
	putchar('\n');
	free(v);
	return 0;
}