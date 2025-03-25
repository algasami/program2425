#include <bits/stdc++.h>

using namespace std;

// minimize manhattan distance
int px[100000], py[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> px[i] >> py[i];
    }

    sort(px, px + n);
    sort(py, py + n);

    int midx = px[n >> 1], midy = py[n >> 1];

    unsigned long long delta = 0;
    for (int i = 0; i < n; i++)
    {
        delta += static_cast<unsigned long long>(abs(midx - px[i])) +
                 static_cast<unsigned long long>(abs(midy - py[i]));
    }

    cout << delta << '\n';

    return 0;
}