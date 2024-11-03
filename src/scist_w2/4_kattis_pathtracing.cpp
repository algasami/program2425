#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

vector<pair<int, int>> path;

char game_map[800][800];
int min_x = 0, max_x = 0;
int min_y = 0, max_y = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	string is;
	int cx = 0, cy = 0;
	while (cin >> is)
	{
		if (is == "left")
		{
			cx--;
		}
		else if (is == "right")
		{
			cx++;
		}
		else if (is == "up")
		{
			cy--;
		}
		else if (is == "down")
		{
			cy++;
		}
		min_x = min(min_x, cx);
		max_x = max(max_x, cx);
		min_y = min(min_y, cy);
		max_y = max(max_y, cy);
		path.push_back({cx, cy});
	}
#ifdef DEBUG
	cout << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << '\n';
#endif
	int w = max_x - min_x + 1;
	int h = max_y - min_y + 1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			game_map[i][j] = ' ';
		}
	}
	for (auto iter = path.begin(); iter != path.end(); iter++)
	{
		game_map[iter->second - min_y][iter->first - min_x] = next(iter) == path.end() ? 'E' : '*';
	}
	game_map[-min_y][-min_x] = 'S';
	cout << string(w + 2, '#') << '\n';
	for (int i = 0; i < h; i++)
	{
		cout << '#';
		for (int j = 0; j < w; j++)
		{
			cout << game_map[i][j];
		}
		cout << "#\n";
	}
	cout << string(w + 2, '#') << '\n';
	return 0;
}