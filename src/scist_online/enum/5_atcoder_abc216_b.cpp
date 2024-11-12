#include <bits/stdc++.h>

using namespace std;

unordered_set<string> vis;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cin.get(); // flush \n
	for (int i = 0; i < n; i++)
	{
		string content;
		getline(cin, content); // this ignores \n
		if (vis.find(content) != vis.end())
		{
			cout << "Yes\n";
			return 0;
		}
		vis.insert(content);
	}
	cout << "No";
	return 0;
}