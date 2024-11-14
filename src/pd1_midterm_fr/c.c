#include <stdio.h>

int is_prime(int n)
{
	if (n <= 1)
	{
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int x = 1; x < n; x++)
	{
		int y = n - x;
		if (is_prime(x) && is_prime(y))
		{
			printf("%d %d\n", x, y);
			return 0;
		}
	}
	printf("What?");
	return 0;
}