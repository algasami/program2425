#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    c -= a;
    d -= b;

    if (d < 0)
    {
        d += 60;
        --c;
    }
    if (c < 0)
    {
        c += 24;
    }
    cout << "totally " << c << " hours and " << d << " minutes.\n";

    return 0;
}
