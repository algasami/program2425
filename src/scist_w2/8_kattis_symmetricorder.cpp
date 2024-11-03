#include <bits/stdc++.h>

using namespace std;

int solve()
{
	static int n = 0;
	int x;
	cin >> x;
	if (!x)
	{
		return 1;
	}
	cout << "SET " << ++n << '\n';
	vector<string> sym;
	for (int i = 0; i < x; i++)
	{
		string a;
		cin >> a;
		sym.push_back(a);
	}
	for (int i = 0; i < x; i++)
	{
		if (i % 2 == 0)
		{
			cout << sym[i] << '\n';
		}
	}
	for (int i = x - 1; i >= 0; i--)
	{
		if (i % 2 == 1)
		{
			cout << sym[i] << '\n';
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (!solve())
		;
	return 0;
}