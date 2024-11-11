#include <bits/stdc++.h>

using namespace std;

// A swap left and middle
// B swap middle and right
// C swap left and right

int lut[3] = {1, 0, 0};

void swap(int a, int b)
{
	int tmp = lut[a];
	lut[a] = lut[b];
	lut[b] = tmp;
}

int main()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
		case 'A':
			swap(0, 1);
			break;
		case 'B':
			swap(1, 2);
			break;
		case 'C':
			swap(0, 2);
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (lut[i])
		{
			putchar(i + '1');
		}
	}
	putchar('\n');
	return 0;
}