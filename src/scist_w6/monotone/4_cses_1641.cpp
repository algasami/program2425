#include <bits/stdc++.h>
#define DEBUG
using namespace std;

struct ii
{ // info integer
    int val;
    int ogi; // original index
};

ii a[5000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].val;
        a[i].ogi = i;
    }
    sort(a, a + n, [](auto const &a, auto const &b) {
        if (a.val == b.val)
            return a.ogi < b.ogi;
        return a.val < b.val;
    });

    for (int i = 0; i < n - 2; i++)
    {
        if (a[i].val >= x - 1)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (int j = i + 1; j < n - 1; j++)
        {
            if (a[i].val + a[j].val >= x) // nothing left for the third val
            {
                break;
            }
            int desire = x - a[j].val - a[i].val;
            // desire and lust, get it? the unquenchable desire to get A + B + C = X
            ii *f =
                lower_bound(a + j + 1, a + n, desire, [](ii const &a, int b) { return a.val < b; });
            if (f == a + n || f->val != desire || f->ogi == a[j].ogi)
            {
                continue;
            }
            cout << (a[i].ogi + 1) << ' ' << (a[j].ogi + 1) << ' ' << (f->ogi + 1) << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}
