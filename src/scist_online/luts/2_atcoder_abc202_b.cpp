#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	reverse(str.begin(), str.end());
	for (char c : str)
	{
		if (c == '6')
		{
			c = '9';
		}
		else if (c == '9')
		{
			c = '6';
		}
		putchar(c);
	}
	putchar('\n');
	return 0;
}