#include <bits/stdc++.h>
// #define DEBUG
using namespace std;

inline long long safe_sum(long long n)
{
    return n & 1 ? ((n + 1) >> 1) * n : (n >> 1) * (n + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<long long> a;

    int n;
    long long k, happy = 0, total_amuse = 0;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        a[i] = x;
        total_amuse += x;
    }

    sort(a.begin(), a.end(), greater());

    while (k > 0 && total_amuse > 0)
    {
        for (int i = 0; i < n; i++)
        {
#ifdef DEBUG
            for (int x : a)
            {
                cout << x << ' ';
            }
            cout << '\n';
#endif
            long long cur = a[i];
            long long next_val = i == n - 1 ? 0 : a[i + 1] - 1;

            long long delta = cur - next_val;
            if (delta >= k)
            {
                delta = k;
                k = 0;
                total_amuse -= delta;
                happy += safe_sum(cur) - safe_sum(cur - delta);
                a[i] -= delta;
                break;
            }
            total_amuse -= delta;
            k -= delta;
            happy += safe_sum(cur) - safe_sum(cur - delta);
            a[i] = next_val;
        }
#ifdef DEBUG
        for (int x : a)
        {
            cout << x << ' ';
        }
        cout << '\n';
#endif
    }

    cout << happy << '\n';

    return 0;
}
