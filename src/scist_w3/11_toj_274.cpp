#include <bits/stdc++.h>

using namespace std;

int is_palindrome(string const &str)
{
	if (str.size() <= 1)
		return 1;
	for (unsigned int i = 0; i <= str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str;
		int single = 0;
		for (unsigned int i = 0; i < str.size(); i++)
		{
			string cpy;
			cpy.reserve(str.size());
			unsigned int j = 0;
			while (j < str.size())
			{
				if (j == i)
				{
					j++;
					continue;
				}
				cpy.push_back(str[j++]);
			}
			if (is_palindrome(cpy))
			{
				cout << "YES\n";
				single = 1;
				break;
			}
		}
		if (!single)
		{
			cout << "NO\n";
		}
	}
	return 0;
}