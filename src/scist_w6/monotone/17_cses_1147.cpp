#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int rowsum[1000][1000]; // sum horizontally. zero when hit tree

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cin.get(); // flush newline
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < m; j++)
        {
            char c = cin.get();
            if (c == '*')
                cur = 0;
            else if (c == '.')
                ++cur;
            rowsum[i][j] = cur;
        }
        cin.get(); // flush newline
    }

#ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << rowsum[i][j] << ' ';
        }
        cout << '\n';
    }
#endif
    int best = 0;
    for (int j = 0; j < m; j++)
    {
        int last = rowsum[0][j], lasti = 0; // i since valid
        for (int i = 0; i < n; i++)
        {
            int elem = rowsum[i][j];
            if (elem == 0)
            {
                lasti = i;
                last = elem;
            }
            int area = last * (i - lasti + 1);
            best = max(best, area);
            last = min(last, elem);
        }
    }
    cout << best << '\n';

    return 0;
}
