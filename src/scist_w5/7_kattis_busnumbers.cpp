#include <bits/stdc++.h>

using namespace std;

int arr[1000], len;

int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + len);
    if (len == 1)
    {
        printf("%d\n", arr[0]);
        return 0;
    }
    int space = 0;
    int j = arr[1] - arr[0] > 1 ? 1 : 0;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] - arr[i - 1] > 1)
        {
            if (!space)
            {
                space = 1;
            }
            else
            {
                putchar(' ');
            }
            // split
            if (i - 1 - j >= 1)
            {
                printf("%d%c%d", arr[j], i - 1 - j > 1 ? '-' : ' ', arr[i - 1]);
            }
            else
            {
                printf("%d", arr[i - 1]);
            }
            j = i;
        }
    }
    if (len - 1 == j) // last is cut
    {
        printf(" %d", arr[j]);
    }
    if (len - 1 - j >= 1)
    {
        printf(" %d%c%d", arr[j], len - 1 - j > 1 ? '-' : ' ', arr[len - 1]);
    }
    putchar('\n');
    return 0;
}