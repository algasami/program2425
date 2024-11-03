#include <bits/stdc++.h>

using namespace std;

deque<int> cards;

int main()
{
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int t, x;
		scanf("%d %d", &t, &x);
		if (t == 1)
		{
			cards.push_front(x);
		}
		else if (t == 2)
		{
			cards.push_back(x);
		}
		else if (t == 3)
		{
			printf("%d\n", cards.at(x - 1));
		}
	}
	return 0;
}