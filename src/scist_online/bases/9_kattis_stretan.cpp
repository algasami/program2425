#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
    1		: 1,4,1
    2		: 10,7,2
    3		: 11,44,11
    4		: 100,47,12
    5		: 101,74,21
    6		: 110,77,22
    7		: 111,444,111
    */
    int k;
    cin >> k;
    string buf;
    // https://stackoverflow.com/questions/181596/how-to-convert-a-column-number-e-g-127-into-an-excel-column-e-g-aa
    while (k > 0)
    {
        int modu = (k - 1) & 1;
        buf += modu ? '7' : '4';
        k = (k - modu) >> 1;
    }
    for (auto iter = buf.rbegin(); iter != buf.rend(); iter++)
    {
        cout << (*iter);
    }
    cout << '\n';
    return 0;
}
