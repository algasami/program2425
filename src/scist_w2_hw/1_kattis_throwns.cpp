#include <bits/stdc++.h>

using namespace std;

int n, k, cur = 0;
stack<int> cmds;

void move_to(int offset)
{
	cur = (cur + offset) % n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "undo")
		{
			int m;
			cin >> m;
			while (m--)
			{
				int v = cmds.top();
				cmds.pop();
				move_to(-v);
			}
			continue;
		}
		int v = strtol(cmd.c_str(), NULL, 10);
		cmds.push(v);
		move_to(v);
	}

	cout << (cur >= 0 ? cur : cur + n) << '\n';

	return 0;
}