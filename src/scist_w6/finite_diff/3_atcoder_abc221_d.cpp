#include <bits/stdc++.h>
#define DEBUG
using namespace std;

map<long long, long long> mp;

long long days[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;

        ++mp[a];
        --mp[a + b];
    }

    long long accu = 0;
    long long last = 0;
    for (auto const &p : mp)
    {

        accu += p.second;

        days[accu] += (p.first - last);
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
