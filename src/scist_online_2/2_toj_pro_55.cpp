// https://toj.tfcis.org/oj/pro/55/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> bucket;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        bucket[k]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        cout << bucket[k] << '\n';
    }

    return 0;
}