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

    unsigned long int l = 1, r = 1000000001, m, a, b, x;

    cin >> a >> b >> x;

    if (a + b > x)
    {
        cout << "0\n";
        return 0;
    }

    while (l < r)
    {
        m = (l + r) >> 1;
        unsigned int price = a * m + b * (floor(log10(static_cast<double>(m))) + 1);

        if (price < x)
        {
            if (l == m)
            {
                break;
            }
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
    cout << m << '\n';

    return 0;
}