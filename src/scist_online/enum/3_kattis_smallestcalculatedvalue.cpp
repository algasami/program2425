#include <bits/stdc++.h>

using namespace std;

// enum op
// {
// 	add,
// 	sub,
// 	mul,
// 	div
// };

int operate(int a, int b, int opcode, int *bad)
{
	if (opcode == 0)
	{
		return a + b;
	}
	if (opcode == 1)
	{
		return a - b;
	}
	if (opcode == 2)
	{
		return a * b;
	}
	if (a % b)
	{
		*bad = 1;
		return 0;
	}
	return a / b;
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int smallest = INT_MAX;
	for (int f1 = 0; f1 < 4; f1++)
	{
		for (int f2 = 0; f2 < 4; f2++)
		{
			int bad = 0;
			int val = operate(operate(a, b, f1, &bad), c, f2, &bad);
			if (bad)
			{
				continue;
			}
			if (smallest > val && val >= 0)
			{
				smallest = val;
			}
		}
	}
	printf("%d\n", smallest);
	return 0;
}