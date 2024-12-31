#include <bits/stdc++.h>

using namespace std;

char lut[256] = {};

class LexCompare
{
  public:
    bool operator()(string const &a, string const &b) const
    {
        for (size_t i = 0; i < min(a.size(), b.size()); i++)
        {
            size_t ka = a.at(i), kb = b.at(i);
            if (lut[ka] < lut[kb])
                return true;
            else if (lut[ka] > lut[kb])
                return false;
        }
        return a.size() < b.size();
    }
};

set<string, LexCompare> tree_sorter;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 26; i++)
        lut[cin.get()] = i;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string x;
        cin >> x;
        tree_sorter.insert(std::move(x));
    }
    for (auto const &s : tree_sorter)
    {
        cout << s << '\n';
    }
    return 0;
}
