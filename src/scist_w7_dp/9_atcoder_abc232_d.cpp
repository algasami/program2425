#include <bits/stdc++.h>
#define DEBUG
using namespace std;

bool bmap[100][100];
int dp[100][100] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w;
    cin >> h >> w;
    cin.get();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            bmap[i][j] = cin.get() == '.';
        }
        cin.get();
    }

    if (!bmap[0][0])
    {
        cout << "0\n";
        return 0;
    }

    dp[0][0] = 1;

    int longest = 0;

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
                dp[i][j] = max(dp[i][j - 1], dp[i][j]);
            }

            if (dp[i][j])
            {
                longest = max(longest, dp[i][j]++);
            }
        }

    cout << longest << '\n';

    return 0;
}
