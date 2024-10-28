#include <bits/stdc++.h>

using namespace std;

int A, B, C;
long long best = 0, X, Y;

int main()
{
	scanf("%d %d %d %llu %llu", &A, &B, &C, &X, &Y);
	// two AB pizza = A pizza and B pizza
	// limit is 2 second
	// O(n^2) around 10^10 around 100 seconds!
	// we can optimize this by choosing AB pizza first.
	// since we want to just exceed X and Y
	// we can use subtraction to see how many A and how
	// many B pizzas we need to buy.
	// this way we squashed the range down to O(n) :)
	// Gist: choose the variable with the most influence

	long long maxc = max(X, Y);

	for (long long combo = 0; combo <= maxc; combo += 1)
	{
		// now we have c A, c B pizzas
		long long apizza = max(0ll, X - combo);
		long long bpizza = max(0ll, Y - combo);
		long long money = apizza * A + bpizza * B + combo * 2ll * C;
		if (!best || money < best)
		{
			best = money;
		}
	}

	printf("%lld\n", best);
	return 0;
}