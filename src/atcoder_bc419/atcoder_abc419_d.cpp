#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// use prefix sum to see when to swap.
// dont actually swap the strings plz!!! it's slow
array<int, 500001> psum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;

    int n, m;
    cin >> n >> m;
    s.reserve(n);
    t.reserve(n);

    cin >> s >> t;

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        ++psum[l - 1];
        --psum[r];
    }

    int current = 0;
    for (int i = 0; i < n; i++)
    {
        current += psum[i];
        if (current & 1)
        {
            cout << t[i];
        }
        else
        {
            cout << s[i];
        }
    }
    cout << '\n';

    return 0;
}
