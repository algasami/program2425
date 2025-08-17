#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int, vector<int>, greater<int>> pq;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int opcode;
        cin >> opcode;
        if (opcode == 1)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        else if (opcode == 2)
        {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }

    return 0;
}
