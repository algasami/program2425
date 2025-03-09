#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// value to index (can collide idc)

int a[200000];
map<int, int> vti;
map<int, int> vtf;
// ! Do not use unordered_map unless you can guarantee little to no key collision
// ! Map worse case indexing: log N
// ! Unordered worse case: N (guaranteed TLE when key collision happens too fast)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!vti.count(x))
            vti[x] = i;
        else
            vtf[x] = i;
        a[i] = x;
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int sv = a[i];
        if (sv >= x)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        int d = x - sv;
        if (vti.count(d))
        {
            if (d == sv)
            {
                if (vtf.count(d))
                {
                    cout << (vti[sv] + 1) << ' ' << (vtf[d] + 1) << '\n';
                    return 0;
                }
                continue;
            }
            cout << (vti[sv] + 1) << ' ' << (vti[d] + 1) << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}
