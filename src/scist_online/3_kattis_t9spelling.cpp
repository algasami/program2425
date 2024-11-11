#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<char, string> lut = map<char, string>({{'a', "2"},
											   {'b', "22"},
											   {'c', "222"},
											   {'d', "3"},
											   {'e', "33"},
											   {'f', "333"},
											   {'g', "4"},
											   {'h', "44"},
											   {'i', "444"},
											   {'j', "5"},
											   {'k', "55"},
											   {'l', "555"},
											   {'m', "6"},
											   {'n', "66"},
											   {'o', "666"},
											   {'p', "7"},
											   {'q', "77"},
											   {'r', "777"},
											   {'s', "7777"},
											   {'t', "8"},
											   {'u', "88"},
											   {'v', "888"},
											   {'w', "9"},
											   {'x', "99"},
											   {'y', "999"},
											   {'z', "9999"},
											   {' ', "0"}});
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cin.get(); // flush \n
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		cout << "Case #" << (i + 1) << ": ";
		char last_char = 0;
		for (char c : str)
		{
			string const &code = lut[c];
			if (last_char && lut[last_char][0] == code[0])
			{
				cout << ' ';
			}
			cout << code;
			last_char = c;
		}
		cout << '\n';
	}
	return 0;
}