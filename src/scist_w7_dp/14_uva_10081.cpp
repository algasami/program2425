#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int solve()
{
    long long tiles[100][10] = {};
    int n, k;
    if (!(cin >> k >> n))
    {
        return 0;
    }

    if (k <= 1)
    {
        cout << "100.00000\n";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            long long candidate = 1;
            if (i > 0)
            {
                candidate = tiles[i - 1][j];
                if (j < k)
                {
                    candidate += tiles[i - 1][j + 1];
                }
                if (j > 0)
                {
                    candidate += tiles[i - 1][j - 1];
                }
            }
            tiles[i][j] += candidate;
        }
    }
    long long sums = 0;
    for (int j = 0; j <= k; j++)
    {
        sums += tiles[n - 1][j];
    }

    // use iterate because denominator is large and the numerator is small
    double res = static_cast<double>(sums) * 100.0;
    for (int i = 0; i < n; i++)
    {
        res /= static_cast<double>(k + 1);
    }
    res = round(res * 100000.0) / 100000.0;
    if (res == 0.0)
    {
        res = 0.0;
    }

    cout << fixed << setprecision(5) << res << '\n';
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
