#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef string::const_iterator ct;

struct TFChart
{
	int tt, tf, ft, ff;
#ifdef DEBUG
	void print()
	{
		cout << "{" << tt << tf << ft << ff << "}";
	}
#endif
};

// param: pqrst as binary mask
bool getBool(int param, ct &from, ct const &end)
{
	char c = *from++;
	// single letter
	int i = 5;
	switch (c)
	{
	case 'p':
		i = 4;
		break;
	case 'q':
		i = 3;
		break;
	case 'r':
		i = 2;
		break;
	case 's':
		i = 1;
		break;
	case 't':
		i = 0;
		break;
	default:
		break;
	}
	if (i != 5)
	{
		return (param & (1 << i)) ? true : false;
	}
	if (c == 'N')
	{
		return !getBool(param, from, end);
	}
	bool a = getBool(param, from, end);
	bool b = getBool(param, from, end);
	if (c == 'K')
	{
		return a && b;
	}
	if (c == 'A')
	{
		return a || b;
	}
	if (c == 'C')
	{
		if (a == 1)
		{
			return b;
		}
		return true;
	}
	return a == b;
}

int main()
{
#ifndef DEBUG
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif

	string str;
	while (cin >> str)
	{
		if (str == "0")
		{
			break;
		}
		bool bad = false;
		for (int i = 1; i < (1 << 5); i++)
		{
			ct current_iter = str.begin();
			bool result = getBool(i, current_iter, str.end());
			if (!result)
			{
				bad = true;
				cout << "not\n";
				break;
			}
#ifdef DEBUG
			cout << (result ? "TRUE" : "FALSE") << '\n';
#endif
		}
		if (!bad)
		{
			cout << "tautology\n";
		}
	}
	return 0;
}