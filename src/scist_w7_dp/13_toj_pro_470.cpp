#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int tiles[1000000][2] = {};

int solve()
{
    int n;
    if (!(cin >> n))
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        tiles[i][0] = 0;
        cin >> tiles[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            long long candidate = 0;
            if (i > 0)
            {
                if (j == 0)
                {
                    candidate = max(tiles[i - 1][j], tiles[i - 1][j + 1]);
                }
                else if (j == 1)
                {
                    candidate = tiles[i - 1][j - 1];
                }
            }
            tiles[i][j] += candidate;
        }
    }

    cout << max(tiles[n - 1][0], tiles[n - 1][1]) << '\n';
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (solve())
        ;

    return 0;
}
