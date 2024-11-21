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
// since we can see that no matter where we cut the branch
// the result is still the same (-1 connection)
// as long as there's connection on the round, you can cut the branch
// even: start with odd connection, so alice can severe the last connection
// odd: start with even connection, so bob can severe the last connection
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