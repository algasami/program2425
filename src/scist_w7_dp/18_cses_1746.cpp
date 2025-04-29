#include <bits/stdc++.h>
#define DEBUG
using namespace std;

constexpr long long MODL = 1000000007LL;

long long tiles[100000][101] = {};
int arr[100000] = {};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tiles[i][x] = 1;
        arr[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i] && arr[i] != j)
            {
                continue;
            }
            long long candidate = 1;
            if (i > 0)
            {
                candidate = 0;
                candidate = tiles[i - 1][j];
                if (j > 1)
                {
                    candidate = (tiles[i - 1][j - 1] + candidate) % MODL;
                }
                if (j < m)
                {
                    candidate = (tiles[i - 1][j + 1] + candidate) % MODL;
                }
            }
            tiles[i][j] = candidate;
        }
    }
    long long sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum = (sum + tiles[n - 1][i]) % MODL;
    }
    cout << sum << '\n';

    return 0;
}
