#include <bits/stdc++.h>

using namespace std;

array<int, 8> capacities = {2, 3, 5, 7, 11, 13, 17, 19};
array<int, 8> input_array;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int max_val = 0, target_val = 0;
    for (size_t i = capacities.size(); i > 0; i--)
    {
        max_val *= capacities[i - 1];
        max_val += capacities[i - 1] - 1;
    }
    for (int i = 0; i < 8; i++)
    {
        cin >> input_array[i];
    }
    for (size_t i = capacities.size(); i > 0; i--)
    {
        target_val *= capacities[i - 1];
        target_val += input_array[i - 1];
    }
    cout << (max_val - target_val) << '\n';
    return 0;
}
