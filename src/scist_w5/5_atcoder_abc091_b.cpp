#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unordered_map<string, int> bucket;
    int N, M;
    cin >> N;
    cin.get();
    for (int i = 0; i < N; i++)
    {
        string str;
        getline(cin, str);
        bucket[str]++;
    }
    cin >> M;
    cin.get();
    for (int i = 0; i < M; i++)
    {
        string str;
        getline(cin, str);
        bucket[str]--;
    }
    int best = INT_MIN;
    for (auto &x : bucket)
    {
        if (x.second > best)
        {
            best = x.second;
        }
    }
    cout << max(best, 0) << '\n';
    return 0;
}