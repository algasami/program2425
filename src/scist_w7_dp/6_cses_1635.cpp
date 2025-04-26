#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    vector<long long> dp(1000001, 0);
    dp[0] = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;

    int primitives[100];

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> primitives[i];
    }

    sort(primitives, primitives + n);

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n && primitives[j] <= i; j++)
        {
            dp[i] = (dp[i] + dp[i - primitives[j]]) % 1000000007LL;
        }
    }
    cout << dp[x] << '\n';

    return 0;
}
