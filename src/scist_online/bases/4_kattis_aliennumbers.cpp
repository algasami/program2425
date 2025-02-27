#include <bits/stdc++.h>

using namespace std;

void solve(int case_num)
{
    unordered_map<char, int> sord;
    unordered_map<int, char> tmap;
    int deci = 0;
    string anum, sl, tl, res;
    cin >> anum >> sl >> tl;
    int slen = static_cast<int>(sl.size()), tlen = static_cast<int>(tl.size());
    for (int i = 0; i < slen; i++)
    {
        sord[sl[i]] = i;
    }
    for (int i = 0; i < tlen; i++)
    {
        tmap[i] = tl[i];
    }

    for (auto c : anum) // copying char is cheaper than accessing ptr, aka microoptimization ftw
    {
        deci *= slen;
        deci += sord[c];
    }

    while (deci > 0)
    {
        res += tmap[deci % tlen];
        deci /= tlen;
    }
    cout << "Case #" << case_num << ": ";
    for (int i = res.size() - 1; i >= 0; i--) // signed so no underflow :)
    {
        cout << res[i];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}