#include <bits/stdc++.h>
#define DEBUG
using namespace std;

constexpr long long MODL = 1000000007LL;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long lims[3];
    cin >> n >> lims[0] >> lims[1] >> lims[2];

    long long tiles[50][3] = {};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            long long candidate = lims[j];
            if (i > 0)
            {
                candidate = 0;
                for (int k = 0; k < 3; k++)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    candidate = (candidate + tiles[i - 1][k]) % MODL;
                }
                candidate *= lims[j];
            }
            tiles[i][j] = candidate % MODL;
        }
    }

    cout << (tiles[n - 1][0] + tiles[n - 1][1] + tiles[n - 1][2]) % MODL << '\n';

    return 0;
}
