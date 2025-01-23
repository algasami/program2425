#include <bits/stdc++.h>

using namespace std;

unsigned int shops[100002] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned int d, n, m;
    cin >> d >> n >> m;
    shops[1] = 0;
    shops[n + 1] = d;
    for (unsigned int i = 2; i <= n; i++)
    {
        cin >> shops[i];
    }

    sort(shops + 1, shops + n + 1);

    unsigned long int addval = 0;
    for (unsigned int i = 0; i < m; i++)
    {
        unsigned int buyer;
        cin >> buyer;
        unsigned int l = 0, r = n + 2;
        while (l < r - 1)
        {
            unsigned int m = (l + r) >> 1;
            unsigned int pos = shops[m];
            // cout << l << ' ' << r << ' ' << pos << '\n';
            if (pos > buyer)
            {
                r = m;
            }
            else if (pos < buyer)
            {
                l = m;
            }
            else
            {
                l = r = m;
                break;
            }
        }
        unsigned int m = (l + r) >> 1;
        addval += min({buyer - shops[l], shops[r] - buyer,
                       buyer > shops[m] ? buyer - shops[m] : shops[m] - buyer});
    }
    cout << addval << '\n';
    return 0;
}