#include <bits/stdc++.h>

#define XVAL 10000
#define YVAL 5000
#define ZVAL 1000

using namespace std;

int main()
{
	int N, Y;
	scanf("%d %d", &N, &Y);
	for (int x = N; x >= 0; x--)
		for (int y = N - x; y >= 0; y--)
		{
			int z = N - x - y;
			if (x * XVAL + y * YVAL + z * ZVAL == Y)
			{
				printf("%d %d %d\n", x, y, z);
				return 0;
			}
		}
	printf("-1 -1 -1\n");
	return 0;
}