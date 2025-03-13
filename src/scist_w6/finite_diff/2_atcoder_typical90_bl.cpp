#include <bits/stdc++.h>
// #define DEBUG
using namespace std;

long long diff[100000] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;

    cin >> n >> q;

    long long last;
    cin >> last;

    long long inconv = 0;
    for (int i = 0; i < n - 1; i++)
    {
        long long a;
        cin >> a;
        inconv += abs(a - last);
        diff[i] = a - last;
        last = a;
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        long long v;

        cin >> l >> r >> v;
        l -= 2;
        r -= 1;

        // 1 2 3: 1 1
        // 1 3 4: 2 1
        // 0 2 4: 2 2
        if (l >= 0)
        {
            inconv -= abs(diff[l]);
            diff[l] += v;
            inconv += abs(diff[l]);
        }
        if (r < n - 1)
        {
            inconv -= abs(diff[r]);
            diff[r] -= v;
            inconv += abs(diff[r]);
        }

#ifdef DEBUG
        for (int i = 0; i < n - 1; i++)
        {
            cout << diff[i] << ' ';
        }
        cout << '\n';
#endif

        cout << inconv << '\n';
    }

    return 0;
}
