#include <bits/stdc++.h>

using namespace std;

int N;
int counts[100000] = {};
set<int> elems;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        ++counts[x];
        elems.insert(x); // set<int> auto-sorts
    }

    int i0 = -1, i1 = -1, biggest = 0;
    for (int x : elems) // ordered set, monotonic
    {
        if (i0 == -1)
        {
            i0 = x;
            biggest = counts[x]; // base scenario
        }
        else if (i1 == -1)
        {
            i1 = x;
            int possible;
            if (i1 - i0 == 1) // calculate here first since we won't come back after initializing
            {
                // ..., x, x+1, ...
                possible = counts[i1] + counts[i0];
            }
            else
            {
                // ..., x, x, x, ...
                possible = counts[i1];
            }
            if (possible > biggest)
            {
                biggest = possible;
            }
            continue;
        }
        if (i0 == -1 || i1 == -1)
        {
            continue;
        }
        int d0 = i1 - i0;
        int d1 = x - i1;
        int possible = 0;
        if (d1 == 1 && d0 == 1) // ..., x-1, x, x+1, ...
        {
            possible = counts[x] + counts[i1] + counts[i0];
        }
        // else if(d0 == 1) // meaningless since this can be computed before
        // {
        //     possible = counts[i1] + counts[i0];
        // }
        // ^ Gist: ..., x-1, x, ... is the same as ..., x, x+1, ...
        else if (d1 == 1) // ..., x, x+1, ...
        {
            possible = counts[x] + counts[i1];
        }
        else
        {
            possible = counts[x];
        }
        if (possible > biggest)
        {
            biggest = possible;
        }
        i0 = i1;
        i1 = x;
    }

    cout << biggest << '\n';
    return 0;
}