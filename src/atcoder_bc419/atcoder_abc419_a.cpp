#include <bits/stdc++.h>
#define DEBUG
using namespace std;

constexpr size_t MTSIZE = 3;

constexpr int MAXLEN = 5;
constexpr int SET_LEN = 'z' - 'a' + 1;
const array<pair<string, string>, MTSIZE> arr({pair("red", "SSS"), pair("blue", "FFF"),
                                               pair("green", "MMM")});

inline int calc_hash(string str)
{
    int hash = 0;

    for (char c : str)
        hash = hash * SET_LEN + (c - 'a');

    return hash;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    array<int, MTSIZE> hashes;
    for (size_t i = 0; i < MTSIZE; i++)
    {
        hashes[i] = calc_hash(arr[i].first);
    }

    string s;
    cin >> s;

    int accuhash = 0;
    size_t acculen = 0;

    string res = "";
    res.reserve(5 * s.size());

    for (size_t i = 0; i < s.size(); ++i)
    {
        accuhash = accuhash * SET_LEN + (s[i] - 'a');
        ++acculen;

        size_t idx = find(hashes.begin(), hashes.end(), accuhash) - hashes.begin();
        if (idx < hashes.size())
        {
            res += arr[idx].second;
            acculen = 0;
            accuhash = 0;
        }
        else if (acculen >= MAXLEN)
        {
            cout << "Unknown\n";
            return 0;
        }
    }

    if (acculen > 0)
    {
        cout << "Unknown\n";
        return 0;
    }

    cout << res << '\n';

    return 0;
}
