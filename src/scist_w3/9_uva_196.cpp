#include <bits/stdc++.h>

using namespace std;

#define DEBUG

int mat[1000][20000];

struct Resolve
{
	int i, j;
	string str;
};
void solve()
{
	memset(mat, 0, sizeof(mat));

	int r, c;
	cin >> c >> r;
	vector<Resolve> evals;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			string str;
			cin >> str;
			if (str[0] != '=')
			{
				mat[i][j] = atoi(str.c_str());
			}
			else
			{
				int ti, tj;
				evals.push_back(Resolve{.i = i, .j = j, .str = str});
			}
		}
	}
	for (auto const &sth : evals)
	{
#ifdef DEBUG
		cout << '(' << sth.i << ',' << sth.j << ") " << sth.str << '\n';
#endif
	}
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
		solve();
	}
	return 0;
}