#include <bits/stdc++.h>
#define DEBUG
using namespace std;

map<int, int> mp;

int days[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        ++mp[a];
        --mp[a + b];
    }

    int accu = 0;
    int last = 0;
    for (auto const &p : mp)
    {

        days[accu] += (p.first - last);
        accu += p.second;
        // cout << "t: " << p.first << ' ' << accu << '\n';
        last = p.first;
    }

    for (int i = 1, f = 1; i <= n; i++)
    {
        if (f == 1)
        {
            f = 0;
        }
        else
        {
            cout << ' ';
        }
        cout << days[i];
    }
    cout << '\n';

    return 0;
}
