#include <bits/stdc++.h>
// #define DEBUG
using namespace std;

vector<pair<long long, long long>> vec;
vector<long long> vecx, vecy;
long long calc_max_mh(long long r, long long c)
{
#ifdef DEBUG
    cout << "Calc for (" << r << "," << c << ")\n";
#endif
    long long mh = 0LL;
    for (const auto &p : vec)
    {
        long long dist = max(abs(p.first - r), abs(p.second - c));
#ifdef DEBUG
        cout << "(" << p.first << "," << p.second << ") - " << dist << "\n";
#endif
        mh = max(mh, dist);
    }
    return mh;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vec.resize(n);
    vecx.resize(n);
    vecy.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
        vecx[i] = vec[i].first;
        vecy[i] = vec[i].second;
    }
    sort(vecx.begin(), vecx.end());
    sort(vecy.begin(), vecy.end());
    double rbound = static_cast<double>(vecx[n - 1] - vecx[0]) / 2.0;
    double cbound = static_cast<double>(vecy[n - 1] - vecy[0]) / 2.0;
    cout << static_cast<long long>(max(ceil(rbound), ceil(cbound))) << '\n';
    // * minimizes Chebyshev distance
    // * aka creating a minimum axis-aligned bounding box
    // * the distance would just be half of the box
    // https://math.stackexchange.com/questions/708822/what-minimizes-the-chebyshev-distance

    return 0;
}
