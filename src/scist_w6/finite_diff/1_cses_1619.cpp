#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int n;

struct pn
{
    int t;    // time
    int diff; // +1 or -1
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<pn> a;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        a.emplace_back(pn{.t = s, .diff = 1});
        a.emplace_back(pn{.t = e, .diff = -1});
    }
    sort(a.begin(), a.end(), [](auto const &a, auto const &b) {
        if (a.t == b.t)
        {
            return a.diff < b.diff;
        }
        return a.t < b.t;
    });

    int current = 0, best = 0;
    for (auto const &x : a)
    {
        if (best < current)
        {
            best = current;
        }
        current += x.diff;
    }

    cout << best << '\n';

    return 0;
}
