#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<long long> a;

    int n;
    long long k, happy = 0;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater());
#ifdef DEBUG
    for (int x : a)
    {
        cout << x << ' ';
    }
    cout << '\n';
#endif

    for (int i = 0; i < n; i++)
    {
        long long cur = a[i];
        long long next_val = i == n - 1 ? 0 : a[i + 1];

        long long delta = cur - next_val;
        if (delta >= k)
        {
            k = 0;
            if (delta > k)
            {
                delta = k;
            }
            break;
        }
        k -= delta;
        happy += (cur / 2 * (cur - 1))
    }

    return 0;
}
