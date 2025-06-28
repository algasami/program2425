#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    size_t n;
    cin >> n;

    string str;
    str.reserve(n);

    cin >> str;

    size_t found = str.find("lv");

    if (found < str.size())
    {
        cout << "0\n";
        return 0;
    }
    auto pl = accumulate(str.begin(), str.end(), pair<int, int>(0, 0),
                         [](pair<int, int> p, const char &elem) {
                             if (elem == 'l')
                             {
                                 p.first++;
                             }
                             else if (elem == 'v')
                             {
                                 p.second++;
                             }
                             return p;
                         });
    if (pl.first || pl.second)
    {
        cout << "1\n";
    }
    else
    {
        cout << "2\n";
    }

    return 0;
}
