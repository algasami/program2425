#include <bits/stdc++.h>
#define DEBUG
using namespace std;

/**
 * Notice first in a triangle, powder can catch peach, and in a rectangle, powder can never catch
 * peach. Notice triangle has 3 edges and rectangle has 4. As long as the total graph of a polygon
 * has the edges of even count, powder can never catch peach.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    cin >> x;
    int totalval = x - 1 + (x / 2); // xC2

    cout << (totalval & 1 ? "No" : "Yes") << '\n';

    return 0;
}
