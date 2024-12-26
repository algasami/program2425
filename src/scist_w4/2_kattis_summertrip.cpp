#include <bits/stdc++.h>

using namespace std;

#define DEBUG

int event_psum[26][100005] = {}; // prefix sum for events

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	size_t len = s.size();
	for (size_t i = 0; i < len; i++)
	{
		event_psum[s[i] - 'a'][i]++;
		for (size_t j = 0; j < 26; j++)
		{
			event_psum[j][i + 1] += event_psum[j][i];
		}
	}

	unsigned long long good_trip = 0;
	for (size_t i = 0; i < len - 1; i++)
	{
		size_t start_ch = s[i] - 'a';
		for (size_t j = i + 1; j - i < 26 && j < len; j++)
		{
			size_t end_ch = s[j] - 'a';
			if (start_ch == end_ch)
			{
				continue;
			}
			size_t start_count = event_psum[start_ch][j] - event_psum[start_ch][i] + 1;
			if (start_count != 1)
			{
				break;
			}
			size_t end_count = event_psum[end_ch][j] - event_psum[end_ch][i];
			if (start_count == 1 && end_count == 1)
			{
#ifdef DEBUG
				cout << string_view(s).substr(i, j - i + 1) << '\n';
#endif
				good_trip++;
			}
		}
	}
	cout << good_trip << '\n';

	return 0;
}
