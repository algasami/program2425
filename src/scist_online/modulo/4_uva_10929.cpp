#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string buffer;
	while (cin >> buffer)
	{
		if (buffer == "0")
		{
			break;
		}

		int odd_sum = 0;
		size_t i = 0;
		for (char c : buffer)
		{
			if (i & 1)
			{
				odd_sum += c - '0';
			}
			else
			{
				odd_sum -= c - '0';
			}
			i++;
		}
		cout << buffer;
		cout << ((odd_sum && odd_sum % 11) ? " is not" : " is") << " a multiple of 11.\n";
	}
	return 0;
}