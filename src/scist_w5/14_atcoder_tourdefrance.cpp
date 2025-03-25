#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int solve()
{
    int f, r;
    int front[10], rear[10];
    vector<float> ratios;
    ratios.reserve(100);

    cin >> f;
    if (!f)
    {
        return 0;
    }
    cin >> r;
    for (int i = 0; i < f; i++)
    {
        cin >> front[i];
    }
    for (int i = 0; i < r; i++)
    {
        cin >> rear[i];
    }

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < r; j++)
        {
            ratios.push_back(static_cast<float>(rear[j]) / static_cast<float>(front[i]));
        }
    }

    sort(ratios.begin(), ratios.end());
    float max_spread = 0.0;

    for (size_t i = 0; i < ratios.size() - 1; i++)
    {
        float spread = ratios[i + 1] / ratios[i];
        max_spread = max(max_spread, spread);
    }
    cout << fixed << setprecision(2) << max_spread << '\n';
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (solve())
        ;
    return 0;
}
