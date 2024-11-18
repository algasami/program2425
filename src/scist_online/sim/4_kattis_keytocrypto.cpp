#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

string cipher, key, buffer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> cipher >> key;
	int j = 0;
	do
	{
#ifdef DEBUG
		cout << key << '\n';
#endif
		char c = (cipher.at(j) - key.at(j)) % 26;
		if (c < 0)
		{
			c += 26;
		}
		c += 'A';

		buffer.push_back(c);
		key.push_back(c);
	} while (++j < cipher.size());
	cout << buffer << '\n';
	return 0;
}