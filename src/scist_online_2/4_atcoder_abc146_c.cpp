#include <bits/stdc++.h>
using namespace std;

/**
 * Synopsis
 * Figure out the largest integer bewtween 1~10^9 Takahashi can buy with X
 * for the price of A * y + B * floor(log_10(y) + 1).
 * The price function is strictly increasing, so instead of O(n) we can use
 * binary search to find the largest integer we can buy.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned long int l = 0, r = 1000000001, m, a, b, x;

    cin >> a >> b >> x;

    if (a + b > x)
    {
        cout << "0\n";
        return 0;
    }

    while (l < r - 1)
    {
        // cout << l << ' ' << r << '\n';
        m = (l + r) >> 1;
        unsigned int i = 1;
        unsigned long int k = m;
        while (k /= 10)
        {
            i++;
        }
        unsigned long int price = a * m + b * i;

        if (price < x)
        {
            l = m;
        }
        else if (price > x)
        {
            r = m;
        }
        else
        {
            break;
        }
    }
    cout << ((l + r) >> 1) << '\n';

    return 0;
}