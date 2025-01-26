#include <bits/stdc++.h>

using namespace std;

/**
 * 0~10^9 range query. not feasible with O(n). use binary search and monotonous property
 */

int arr[100002], n;

int bin_search(int x, int f)
{
    int l = 0, r = n + 1;
    while (l < r - 1)
    {
        int m = (l + r) >> 1;

        if (arr[m] > x)
        {
            r = m;
        }
        else if (arr[m] < x)
        {
            l = m;
        }
        else
        {
            break;
        }
    }

    return f ? r : l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int li, ri;
        cin >> li >> ri;

        int l = bin_search(li, 0);
        int r = bin_search(ri, 1);
        // cout << l << ' ' << r << '\n';
        int k = r - l - 1;
        for (int j = l + 1; j < r && arr[j] < li; j++, k--)
            ;
        for (int j = r - 1; j > l && arr[j] > ri; j--, k--)
            ;
        cout << k << '\n';
    }

    return 0;
}