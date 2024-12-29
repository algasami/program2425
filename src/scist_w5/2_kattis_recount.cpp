#include <bits/stdc++.h>

using namespace std;

map<string, int> bucket;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true)
    {
        string line;
        getline(cin, line); // does not include \n
        bucket[line]++;
        if (line == "***")
        {
            break;
        }
    }
    int biggest = 0, same = 1;
    const string *biggest_name = nullptr;
    for (const auto &x : bucket)
    {
        if (biggest < x.second)
        {
            biggest = x.second;
            biggest_name = &x.first;
            same = 0;
        }
        else if (biggest == x.second)
        {
            same = 1;
        }
    }
    // biggest_name should never be nullptr unless no participant
    if (same)
    {
        cout << "Runoff!\n";
    }
    else
    {
        cout << *biggest_name << '\n';
    }
    return 0;
}