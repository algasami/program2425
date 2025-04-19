#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // 1 2 3, sum possibilities
    // need permutation

    int dp[25] = {0, 1, 2, 4};

    for (int i = 4; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            dp[i] += dp[i - j]; // permutate primitive so it's always 1
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
