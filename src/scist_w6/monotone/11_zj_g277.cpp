#include <bits/stdc++.h>
// #define DEBUG
using namespace std;

struct vs
{
    int val;
    int loc;
};

int n, qry = 0;

// pretty unoptimized RMQ, but since our query
// only goes bigger and more limiting, this is actually nice
// since i can do this in one pass
vs a[300000];
long long ps[300001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ps[0] = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i].val = x;
        a[i].loc = i;
        ps[i + 1] = x + ps[i];
    }

    sort(a, a + n, [](auto const &a, auto const &b) {
        if (a.val == b.val)
        {
            return a.loc < b.loc;
        }
        return a.val < b.val;
    });

    int l = 0, r = n;

    while (l < r - 1)
    {
        // skip all the OOB minimum value
        while (a[qry].loc < l || a[qry].loc >= r)
            ++qry;
        if (qry >= n)
        {
            break;
        }

        int m = a[qry++].loc;

        long long lsum = ps[m] - ps[l];
        long long rsum = ps[r] - ps[m + 1];

#ifdef DEBUG
        cout << '[' << l << ", " << m << ") - (" << m << ", " << r << ")\n";
        cout << "lsum: " << lsum << " rsum: " << rsum << '\n';
#endif
        if (lsum >= rsum)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << ps[l + 1] - ps[l] << '\n';

    return 0;
}
