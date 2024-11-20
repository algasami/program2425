#include <bits/stdc++.h>

using namespace std;

string chart("ABCDEFGHIJKLMNOPQRSTUVWXYZ_.");
unordered_map<char, size_t> char_to_i;

int solve()
{
	size_t rot;
	cin >> rot;
	if (!rot)
	{
		return 1;
	}
	string str;
	cin >> str;
	for (auto iter = str.rbegin(); iter != str.rend(); iter++)
	{
		size_t index = (char_to_i[*iter] + rot) % chart.size();
		cout << chart[index];
	}
	cout << '\n';
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	size_t i = 0;
	for (char c : chart)
	{
		char_to_i[c] = i++;
	}
	while (!solve())
		;
	return 0;
}