#include <bits/stdc++.h>

using namespace std;

vector<string> buffer;
vector<list<int>> items;
int n, protag = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		items.push_back(list<int>({i}));
		buffer.push_back(std::move(str));
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		items[a].splice(items[a].end(), items[b]);
		// splice moves the second list into the iterator's position with O(1) complexity
		protag = a;
	}
	for (int x : items[protag])
	{
		cout << buffer[x];
	}
	cout << '\n';
	return 0;
}