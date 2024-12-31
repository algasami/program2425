#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int r;
        cin >> r;
        vector<int> v, prefix;
        long long int agg = 0;
        v.resize(r);
        for (int j = 0; j < r; j++)
        {
            cin >> v[j];
            agg += v[j];
        }
        sort(v.begin(), v.end());
        prefix.resize(r + 1);
        prefix[0] = 0;
        for (int j = 1; j <= r; j++)
        {
            prefix[j] = prefix[j - 1] + v[j - 1];
        }
        long long int smol = LONG_MAX;
        for (int j = 0; j < r; j++)
        {
            // O(n) instead of O(n^2)
            // 1, 2, 3, 4, ref, 5, 6, 7, 8
            long long int sum = (j * v[j] - (prefix[j] - prefix[0])) +
                                ((prefix[r] - prefix[j + 1]) - (r - j - 1) * v[j]);
            if (sum < smol)
            {
                smol = sum;
            }
        }
        cout << smol << '\n';
    }
    return 0;
}