#include <bits/stdc++.h>

using namespace std;

int H, W;
int sum_row[2000] = {};
int sum_col[2000] = {};
int a[2000][2000] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			int x;
			cin >> x;
			sum_row[i] += x;
			sum_col[j] += x;
			a[i][j] = x;
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0, first = 1; j < W; j++)
		{
			if (first)
			{
				first = 0;
			}
			else
			{
				cout << ' ';
			}
			cout << (sum_row[i] + sum_col[j] - a[i][j]);
		}
		cout << '\n';
	}

	return 0;
}