#include <stdio.h>

/*
Write a function that uses a 1-D array to store the Pascal's triangle.
Example:
1.............................(First line)
1 1..........................(Second line)
1 2 1.......................(Third line)
1 3 3 1 .
1 4 6 4 1 .
1 5 10 10 5 1 .
1 6 15 20 15 6 1 .
1 7 21 35 35 21 7 1 .

1-D array should store the content: 1 1 1 1 2 1 1 3 3 1 1 4 6 4 1 1 5 10 10 5 1 ......
Write another function as follows: The function returns the value based on the row and col.
int Pascal(int row, int col)
{ ... }
Ex: Pascal(5,3), it returns 6.
*/

unsigned long long arr[100001] = {0}, max_r = 0;

unsigned long long pascal(int r, int c)
{
	if (c < 1 || c > r)
	{
		return 0;
	}
	int index = r * (r - 1) / 2 - 1 + c;
	if (!arr[index])
	{
		arr[index] = pascal(r - 1, c - 1) + pascal(r - 1, c);
		if (r > max_r)
		{
			max_r = r;
		}
	}
	return arr[index];
}

int main()
{
	arr[0] = 1;
	int a, b;
	do
	{
		scanf("%d %d", &a, &b);
		printf("Pascal(%d, %d) = %llu\nCurrent Triangle:\n", a, b, pascal(a, b));
		for (int r = 1; r <= max_r; r++)
		{
			for (int c = 1; c <= r; c++)
			{
				int index = r * (r - 1) / 2 - 1 + c;
				if (!arr[index])
				{
					arr[index] = pascal(r, c);
				}
				if (c > 1)
				{
					putchar(' ');
				}
				printf("%llu", arr[index]);
			}
			putchar('\n');
		}
	} while (a && b);
	return 0;
}