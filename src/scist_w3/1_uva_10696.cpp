#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
	if (x <= 100)
	{
		return 91;
	}
	return x - 10;
}

int main()
{
	int x;
	while (1)
	{
		scanf("%d", &x);
		if (!x)
		{
			break;
		}
		printf("f91(%d) = %d\n", x, f(x));
	}
	return 0;
}