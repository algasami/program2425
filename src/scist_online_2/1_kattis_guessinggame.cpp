#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        int bad = 0, upb = 11, lowb = 0, good = 1;
        while (1)
        {
            int x;
            string expr;
            cin >> x;
            if (x == 0)
            {
                bad = 1;
                break;
            }
            cin.get();
            getline(cin, expr);
            if (expr == "too high")
            {
                upb = min(upb, x);
            }
            else if (expr == "too low")
            {
                lowb = max(lowb, x);
            }
            else if (expr == "right on")
            {
                if (x >= upb || x <= lowb)
                {
                    good = 0;
                }
                break;
            }
            if (upb <= lowb)
            {
                good = 0;
            }
        }
        if (bad)
        {
            break;
        }
        if (good)
        {
            cout << "Stan may be honest\n";
        }
        else
        {
            cout << "Stan is dishonest\n";
        }
    }
    return 0;
}