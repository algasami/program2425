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
        elems.insert(x);
    }

    int i0 = -1, i1 = -1, biggest = 0;
    for (int x : elems) // ordered set, monotonic
    {
        if (i0 == -1)
        {
            i0 = x;
            biggest = counts[x]; // initiate
        }
        else if (i1 == -1)
        {
            i1 = x;
            int possible;
            if (i1 - i0 == 1)
            {
                possible = counts[i1] + counts[i0];
            }
            else
            {
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
        if (d1 == 1 && d0 == 1)
        {
            possible = counts[x] + counts[i1] + counts[i0];
        }
        // else if(d0 == 1) // meaningless since this can be computed before
        // {
        //     possible = counts[i1] + counts[i0];
        // }
        else if (d1 == 1)
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

    // notice the monotonic property of the array
    // array can never be empty

    return 0;
}