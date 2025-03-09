#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// !almost identical to the fifth question

int a[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            cout << n << '\n';
            return 0;
        }
    }

    int big_len = 0;
    long long prod = 1;
    // now a[i] > 0
    for (int i = 0, j = 0; i < n && j <= i; i++)
    {
        prod *= a[i];
        // keep two indices
        // if accumulated is bigger than x, we sub tail becaues of monotonous quality
        while (prod > x && j < n)
            prod /= a[j++];

        // cout << i << ' ' << ' ' << j << ' ' << prod << '\n';
        if (prod <= x && big_len < (i - j + 1))
        {
            big_len = i - j + 1;
        }
    }
    cout << big_len << '\n';

    return 0;
}
