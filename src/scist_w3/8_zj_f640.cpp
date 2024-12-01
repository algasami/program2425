#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
	return 2 * x - 3;
}

int g(int x, int y)
{
	return 2 * x + y - 7;
}

int h(int x, int y, int z)
{
	return 3 * x - 2 * y + z;
}

int read_exp()
{
	string str;
	cin >> str;
	if (str[0] == 'h')
	{
		int a = read_exp();
		int b = read_exp();
		int c = read_exp();
		return h(a, b, c);
	}
	if (str[0] == 'g')
	{
		int a = read_exp();
		int b = read_exp();
		return g(a, b);
	}
	if (str[0] == 'f')
	{
		return f(read_exp());
	}

	return atoi(str.c_str());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << read_exp() << '\n';
	return 0;
}