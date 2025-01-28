#include <bits/stdc++.h>

using namespace std;

// #define DEBUG

int ucount[26] =
    {}; // when ending with character C, the total unique combination currently is ucount[C].
unsigned long long had_prev[26][26] =
    {}; // had_prev[A][B] = When encountering character A, we have seen B (aka B is BEFORE A)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    getline(cin, s);

    size_t len = s.size();
    unsigned long long good_trip = 0;
    for (size_t i = 0; i < len; i++)
    {
        size_t ch = s[i] - 'a';
        good_trip += ucount[ch];
        ucount[ch] = 0; // reset unique combination (we've registered)
        memset(had_prev[ch], 0,
               sizeof(had_prev[ch])); // reset everything for ch being the start (because we
                                      // just saw B = jettisoned ucount)
        // ^ This make sure strings like `aab` only count for the second a because it is unique
        for (size_t j = 0; j < 26; j++)
        {
            if (j == ch)
            {
                continue;
            }
            if (!had_prev[j][ch]) // haven't seen ch yet (unique)
            {
                had_prev[j][ch] = 1;
                ucount[j]++; // should we encounter j in the future, we will get the unique combo
                // uncertainty = cache
            }
        }
    }

    cout << good_trip << '\n';

    return 0;
}
