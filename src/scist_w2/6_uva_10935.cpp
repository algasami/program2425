#include <bits/stdc++.h>

using namespace std;

int solve()
{
	queue<int> cards;
	int n;
	scanf("%d", &n);
	if (!n)
	{
		return 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cards.push(i);
	}

	printf("Discarded cards:");
	bool comma = false;
	while (cards.size() > 1)
	{
		if (comma)
		{
			printf(",");
		}
		comma = true;
		printf(" %d", cards.front());
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}
	printf("\nRemaining card: %d\n", cards.front());

	return 0;
}

int main()
{
	while (!solve())
		;
	return 0;
}