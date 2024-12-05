#include <bits/stdc++.h>

using namespace std;

// #define DEBUG

typedef string::const_iterator ci;
typedef pair<int, int> ij;

int mat[1000][20000];

ij get_ij(ci &str_index, ci const &str_end)
{
	int j = 0, i = 0;
	while (str_index != str_end)
	{
		if (isdigit(*str_index))
		{
			i *= 10;
			i += (*str_index - '0');
		}
		if (isalpha(*str_index))
		{
			j *= 26;
			j += (*str_index - 'A' + 1);
		}
		if (*str_index == '+')
		{
			break;
		}
		str_index++;
	}
	i--;
	j--;
#ifdef DEBUG
	cout << i << ',' << j << '\n';
#endif
	return pair<int, int>(i, j);
}

vector<int> tpsort;
unordered_map<int, bool> visited;
unordered_map<int, vector<int>> adjs;

void dfs_sort(int x)
{
	if (visited[x])
	{
		return;
	}
	visited[x] = true;
	int k = 0;
	for (auto const &t : adjs[x])
	{
		dfs_sort(t);
		k++;
	}
	tpsort.push_back(x);
}

ij get_ij_from_index(int x, int c)
{
	return ij(x / c, x % c);
}

void solve()
{
	memset(mat, 0, sizeof(mat));

	int r, c;
	cin >> c >> r;
	tpsort.clear();
	visited.clear();
	adjs.clear();
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
				ci iter = str.begin();
				int myindex = i * c + j;
				while (true)
				{
					ij coords = get_ij(iter, str.end());
					adjs[myindex].push_back(coords.first * c + coords.second);
					if (iter == str.end())
					{
						break;
					}
					iter++;
				}
#ifdef DEBUG
				cout << '(' << i << ',' << j << ") " << str << '\n';
#endif
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int ind = i * c + j;
			if (!visited[ind])
			{
				dfs_sort(ind);
			}
		}
	}
	for (int index : tpsort)
	{
		// eval
		ij coord = get_ij_from_index(index, c);
		int sum = mat[coord.first][coord.second];
		for (int adj : adjs[index])
		{
			ij other_coord = get_ij_from_index(adj, c);
			sum += mat[other_coord.first][other_coord.second];
		}
		mat[coord.first][coord.second] = sum;
	}
	for (int i = 0; i < r; i++)
	{
		bool space = false;
		for (int j = 0; j < c; j++)
		{
			if (!space)
			{
				space = true;
			}
			else
			{
				cout << ' ';
			}
			cout << mat[i][j];
		}
		cout << '\n';
	}
}

int main()
{
#ifndef DEBUG
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}
	return 0;
}