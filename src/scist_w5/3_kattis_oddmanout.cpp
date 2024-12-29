#include <bits/stdc++.h>

using namespace std;

void solve(int n)
{
    int gcount;
    scanf("%d", &gcount);
    unordered_map<int, int> bucket;
    for (int i = 0; i < gcount; i++)
    {
        int C;
        scanf("%d", &C);
        bucket[C]++;
    }
    for (const auto &p : bucket)
    {
        if (p.second == 1)
        {
            printf("Case #%d: %d\n", n, p.first);
            break;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        solve(i);
    return 0;
}