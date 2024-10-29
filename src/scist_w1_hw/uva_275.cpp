#include <bits/stdc++.h>

using namespace std;

int solve()
{
	int left[1001][1001] = {0}; // left[remainder] = has or not
	int a, b;
	scanf("%d %d", &a, &b);
	if (a == 0 || b == 0)
	{
		return 1;
	}
	putchar('.');
	// a < b
	int bufferlength = 1;
	int repeat = 0, term = 0;
	while (1)
	{
		a *= 10;
		int val = a / b;
		a %= b;
		if (left[a][val])
		{
			repeat -= left[a][val];
			break;
		}
		printf("%d", val);
		if (a == 0)
		{
			term = 1;
			break;
		}
		bufferlength++;
		repeat++;
		left[a][val] = repeat;
		if (bufferlength >= 50)
		{
			putchar('\n');
			bufferlength = 0;
		}
	}
	if (bufferlength)
	{
		putchar('\n');
	}
	if (term)
	{
		puts("This expansion terminates.");
	}
	else
	{
		printf("The last %d digits repeat forever.\n", repeat + 1);
	}
	return 0;
}

int main()
{
	while (!solve())
	{
		putchar('\n');
		// ^ wth!? weird ahh output requirement
	}
	return 0;
}