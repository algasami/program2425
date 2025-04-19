#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;

    cin >> n >> k;

    int arr[100000];
    int dp[100000] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int optimal = INT_MAX;

        for (int j = 1; j <= k && i >= j; j++)
        {
            optimal = min(dp[i - j] + abs(arr[i - j] - arr[i]), optimal);
        }

        dp[i] = optimal;
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
