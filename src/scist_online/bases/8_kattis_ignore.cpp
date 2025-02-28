#include <bits/stdc++.h>
#define DEBUG
using namespace std;

array<char, 7> charset{'0', '1', '2', '5', '9', '8', '6'};
constexpr int total = charset.size();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int deci;
    while (cin >> deci)
    {
        if (deci == 0)
        {
            cout << "0\n";
            continue;
        }
        string buf;
        while (deci > 0)
        {
            buf += charset[deci % total];
            deci /= total;
        }
        cout << buf << '\n';
    }

    return 0;
}
