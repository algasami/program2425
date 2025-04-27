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
                candidate = tiles[i - 1][j];
                if (j >= 1)
                {
                    if (candidate == 0 ||
                        (candidate > tiles[i - 1][j - 1] && tiles[i - 1][j - 1] != 0))
                    {
                        candidate = tiles[i - 1][j - 1];
                    }
                }
            }
            if (candidate == 0 && (i != 0 || j != 0))
            {
                tiles[i][j] = 0;
                continue;
            }
            tiles[i][j] += candidate;
        }
    }

    cout << tiles[n - 1][2] << '\n';

    return 0;
}
