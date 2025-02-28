#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, m;
    cin >> h >> m;
    m -= 45;
    if (m < 0)
    {
        m += 60;
        --h;
    }
    if (h < 0)
    {
        h += 24;
    }
    cout << h << ' ' << m << '\n';
    return 0;
}