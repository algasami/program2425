#include <bits/stdc++.h>

using namespace std;

// 1-2-3-4
// alice: 1-2, 3-4
// bob: 1, 2, 3-4
// alice: 1, 2, 3, 4
// alice wins

// 1-2-3
// alice: 1, 2-3
// bob: 1, 2, 3
// bob wins

// even: alice wins
// odd: bob wins
// TODO: mathematical proof

int main()
{
	int n;
	scanf("%d", &n);
	if (n % 2 == 0)
	{
		puts("Alice\n1");
	}
	else
	{
		puts("Bob");
	}
	return 0;
}