#include <bits/stdc++.h>
#define DEBUG
using namespace std;

long long tiles[200000][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tiles[i][0] >> tiles[i][1] >> tiles[i][2];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            long long candidate = 0;
            if (i >= 1)
            {
                candidate = max(tiles[i - 1][(j + 1) % 3], tiles[i - 1][(j + 2) % 3]);
            }
            tiles[i][j] += candidate;
        }
    }

    cout << max({tiles[n - 1][0], tiles[n - 1][1], tiles[n - 1][2]}) << '\n';

    return 0;
}
