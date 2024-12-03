#include <bits/stdc++.h>

using namespace std;

unsigned long long L[100002] = {};

// S_n = S_(n-2) concat. S_(n-1)
// k is either in the first or the second string
char f(int n, unsigned long long k)
{
	if (n == 1)
	{
		return 'N';
	}
	if (n == 2)
	{
		return 'A';
	}
	if (n > 90)
	{
		return f(n % 2 ? 89 : 90, k);
	}

	if (k <= L[n - 2])
	{
		return f(n - 2, k);
	}
	return f(n - 1, k - L[n - 2]);
}

int main()
{
	L[1] = 1;
	L[2] = 1;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	unsigned long long k;
	cin >> n >> k;
	for (int i = 3; i <= n; i++)
	{
		L[i] = L[i - 1] + L[i - 2];
	}
	cout << f(n, k) << '\n';
	return 0;
}