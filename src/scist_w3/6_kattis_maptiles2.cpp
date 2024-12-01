#include <bits/stdc++.h>

using namespace std;

// iterative solution

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	cin >> str;
	istringstream iss(str);
	int total_level = str.size();
	int x = 0, y = 0;
	for (int i = 0; i < total_level; i++)
	{
		char c = str[i];
		int lx = 0, ly = 0;
		if (c == '1' || c == '3')
		{
			lx = 1;
		}
		if (c == '2' || c == '3')
		{
			ly = 1;
		}

		x = (x << 1) + lx;
		y = (y << 1) + ly;
	}
	cout << total_level << ' ' << x << ' ' << y << '\n';
	return 0;
}