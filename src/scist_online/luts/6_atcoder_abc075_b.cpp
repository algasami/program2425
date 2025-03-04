#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int h, w;
int mat[50][50];
bool is_bomb[50][50] = {};
inline void adj_bomb(int ci, int cj)
{
    for (int i = -1; i <= 1; i++)
    {
        int li = ci + i;
        if (li < 0 || li >= h)
        {
            continue;
        }
        for (int j = -1; j <= 1; j++)
        {
            int lj = cj + j;
            if (lj < 0 || lj >= w)
            {
                continue;
            }
            ++mat[li][lj];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w;
    cin.get(); // flush newline
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c = cin.get();
            if (c == '#')
            {
                is_bomb[i][j] = true;
                adj_bomb(i, j);
            }
        }
        cin.get(); // newline
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (is_bomb[i][j])
            {
                cout << '#';
            }
            else
            {
                cout << mat[i][j];
            }
        }
        cout << '\n';
    }
    return 0;
}
