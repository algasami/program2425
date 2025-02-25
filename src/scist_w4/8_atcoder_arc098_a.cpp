#include <bits/stdc++.h>

using namespace std;
// pref and suff, E = 0, W = 1
int pref[2][300005] = {}, esum = 0, wsum = 0;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> n;
    s.reserve(n);
    cin >> s;

    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'E')
        {
            ++pref[0][i];
            ++esum;
        }
        else
        {
            ++pref[1][i];
            ++wsum;
        }
        pref[0][i + 1] = pref[0][i];
        pref[1][i + 1] = pref[1][i];
    }
    int min_ppl = n;
    for (int i = 0; i < n; i++) // leader code
    {
        int lw = pref[1][i];            // left wants to turn e
        int re = esum - pref[0][i + 1]; // right wants to turn w
        if (lw + re < min_ppl)
        {
            min_ppl = lw + re;
        }
    }
    cout << min_ppl << '\n';

    return 0;
}