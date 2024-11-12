#include <bits/stdc++.h>

using namespace std;

unordered_map<string, bool> already;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0, j = 0; i < n && j < 12; i++)
	{
		string uni_name, team_name;
		cin >> uni_name >> team_name;
		if (already[uni_name])
		{
			continue;
		}
		already[uni_name] = true;
		cout << uni_name << ' ' << team_name << '\n';
		j++;
	}
	return 0;
}