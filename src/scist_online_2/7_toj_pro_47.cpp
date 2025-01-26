#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

int bf[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> bf[i];
    }
    sort(bf + 1, bf + n + 1);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int tg;
        cin >> tg;
        int l = 0, r = n + 1;
        int good = 0;
        while (l < r - 1)
        {
            int m = (l + r) >> 1;
#ifdef DEBUG
            cout << l << ' ' << r << ' ' << bf[m] << '\n';
            cout << "----\n";
#endif
            if (tg < bf[m])
            {
                r = m;
            }
            else if (tg > bf[m])
            {
                l = m;
            }
            else
            {
                l = r = m;
                good = 1;
                break;
            }
        }
        if (good)
        {
            cout << bf[l] << '\n';
        }
        else
        {
            if (l == 0)
            {
                cout << "no " << bf[r] << '\n';
            }
            else if (r == n + 1)
            {
                cout << bf[l] << " no" << '\n';
            }
            else
            {
                cout << bf[l] << ' ' << bf[r] << '\n';
            }
        }
    }
    return 0;
}