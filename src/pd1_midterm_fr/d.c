#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXN 4

int n;
int mat[MAXN][MAXN];
int assigned_task[MAXN];
int assigned_person[MAXN];

int solution[MAXN];

int find_person(int (*p)[MAXN])
{
	int biggest = -1;
	for (int i = 0; i < n; i++)
	{
		if (assigned_person[i] != -1)
		{
			continue;
		}
		if (biggest < 0 || p[i][0] > p[biggest][0])
		{
			biggest = i;
		}
	}
	return biggest;
}

int biggest_sum = INT_MIN;
void optimal(int left, int attention_sum)
{
	if (left == 0)
	{
		if (attention_sum > biggest_sum)
		{
			biggest_sum = attention_sum;
			memcpy(solution, assigned_task, sizeof(assigned_task));
		}
		return;
	}
	for (int t = 0; t < n; t++)
	{
		if (assigned_task[t] != -1)
		{
			continue;
		}
		int chosen = find_person((int(*)[MAXN]) & mat[0][t]);
		if (chosen < 0)
		{
			continue;
		}
		assigned_person[chosen] = t;
		assigned_task[t] = chosen;
		optimal(left - 1, attention_sum + mat[chosen][t]);
		assigned_task[t] = -1;
		assigned_person[chosen] = -1;
	}
}

int main()
{
	memset(assigned_task, -1, sizeof(assigned_task));
	memset(assigned_person, -1, sizeof(assigned_person));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	optimal(n, 0);
	for (int task = 0, good = 0; task < n; task++)
	{
		if (good)
		{
			putchar(' ');
		}
		else
		{
			good = 1;
		}
		printf("%d", solution[task] + 1);
	}
	putchar('\n');

	return 0;
}