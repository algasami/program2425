#include <bits/stdc++.h>
#define DEBUG
using namespace std;

bool bmap[1000][1000];
int dp[1000][1000] = {};

constexpr int LMOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // local adjacency relationship
    // can be optimized with temporary variables

    int h, w;
    cin >> h;
    w = h;

    cin.get();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            bmap[i][j] = cin.get() == '.';
        }
        cin.get(); // forgor...
    }

    dp[0][0] = 1;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            if (!bmap[i][j])
            {
                dp[i][j] = 0;
                continue;
            }
            if (i >= 1)
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (j >= 1)
            {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % LMOD;
            }
        }

    cout << dp[h - 1][w - 1] << '\n';

    return 0;
}
