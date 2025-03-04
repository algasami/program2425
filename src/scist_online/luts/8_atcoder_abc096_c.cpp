#include <bits/stdc++.h>
#define DEBUG
using namespace std;
int h, w;
bool mat[50][50] = {}, visited[50][50];

inline bool is_oob(int i, int j)
{
    return i < 0 || i >= h || j < 0 || j >= w;
}

int count_adjs(int i, int j)
{
    if (is_oob(i, j) || !mat[i][j] || visited[i][j])
    {
        return 0;
    }
    visited[i][j] = 1;
    return count_adjs(i - 1, j) + count_adjs(i + 1, j) + count_adjs(i, j + 1) +
           count_adjs(i, j - 1) + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w;
    cin.get();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (cin.get() == '#')
            {
                mat[i][j] = true;
                // black
            }
        }
        cin.get();
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (!mat[i][j] || visited[i][j])
            {
                continue;
            }
            if (count_adjs(i, j) <= 1)
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";

    return 0;
}
