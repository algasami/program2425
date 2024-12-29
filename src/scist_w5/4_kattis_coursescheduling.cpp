#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<string, unordered_set<string>> courses;
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        string name, course;
        getline(cin, name);
        while (name.back() != ' ')
        {
            course.push_back(name.back());
            name.pop_back();
        }
        reverse(course.begin(), course.end());
        // cout << name << '+' << course << '\n'; // name has a trailing space i don't care
        courses[course].insert(name);
    }
    for (const auto &p : courses)
    {
        cout << p.first << ' ' << p.second.size() << '\n';
    }

    return 0;
}