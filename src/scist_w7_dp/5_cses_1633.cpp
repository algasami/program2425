#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// Ordered pair primitive combinatronics

constexpr long long MODULO = 1000000007LL;

int main()
{
    vector<long long> dp;
    dp.resize(1000001, 0);
    dp[0] = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int primitive = 1; primitive <= i && primitive <= 6; primitive++)
        {
            dp[i] = (dp[i - primitive] + dp[i]) % MODULO;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
