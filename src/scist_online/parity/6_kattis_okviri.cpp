#include <bits/stdc++.h>
#define DEBUG
using namespace std;

char fb[5][75];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(fb, '.', sizeof(fb));

    string str;
    cin >> str;

    for (int i = 0; i < static_cast<int>(str.size()); i++)
    {
        int anchor = i * 4;
        char tg = (i + 1) % 3 ? '#' : '*';
        fb[0][anchor + 2] = fb[1][anchor + 1] = fb[1][anchor + 3] = fb[2][anchor + 4] =
            fb[3][anchor + 1] = fb[3][anchor + 3] = fb[4][anchor + 2] = tg;
        if (i % 3 || !i)
        {
            fb[2][anchor] = tg;
        }

        fb[2][anchor + 2] = str.at(i);
    }
    for (int iy = 0; iy < 5; iy++)
    {
        for (int i = 0; i < static_cast<int>(str.size()) * 4 + 1; i++)
        {
            cout << fb[iy][i];
        }
        cout << '\n';
    }

    return 0;
}
