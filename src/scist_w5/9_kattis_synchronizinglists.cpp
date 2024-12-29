#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int space = 0;
    while (1)
    {
        scanf("%d", &n);
        if (!n)
        {
            break;
        }
        if (space)
        {
            putchar('\n');
        }
        else
        {
            space = 1;
        }
        vector<int> fsort;
        vector<int> lsort;
        fsort.reserve(n);
        lsort.reserve(n);
        map<int, int> flist;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            flist[x] = i;
            fsort.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            lsort.push_back(x);
        }
        sort(fsort.begin(), fsort.end());
        sort(lsort.begin(), lsort.end());
        vector<int> result;
        result.resize(n);
        for (int i = 0; i < n; i++)
        {
            result[flist[fsort[i]]] = lsort[i];
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", result[i]);
        }
    }
    return 0;
}