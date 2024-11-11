#include <bits/stdc++.h>

using namespace std;

map<string, int> months({
	{"Jan", 1},
	{"Feb", 2},
	{"Mar", 3},
	{"Apr", 4},
	{"May", 5},
	{"Jun", 6},
	{"Jul", 7},
	{"Aug", 8},
	{"Sep", 9},
	{"Oct", 10},
	{"Nov", 11},
	{"Dec", 12},
});

/**
 * -1: a < b
 * 0: a == b
 * 1: a > b
 */
int comp(int ad, string am, int bd, string bm)
{
	if (months[am] < months[bm])
	{
		return -1;
	}
	if (months[am] > months[bm])
	{
		return 1;
	}
	if (ad < bd)
	{
		return -1;
	}
	if (ad > bd)
	{
		return 1;
	}
	return 0;
}

map<string, array<pair<string, int>, 2>> segments({
	{"Aries", {make_pair("Mar", 21), make_pair("Apr", 20)}},
	{"Taurus", {make_pair("Apr", 21), make_pair("May", 20)}},
	{"Gemini", {make_pair("May", 21), make_pair("Jun", 21)}},
	{"Cancer", {make_pair("Jun", 22), make_pair("Jul", 22)}},
	{"Leo", {make_pair("Jul", 23), make_pair("Aug", 22)}},
	{"Virgo", {make_pair("Aug", 23), make_pair("Sep", 21)}},
	{"Libra", {make_pair("Sep", 22), make_pair("Oct", 22)}},
	{"Scorpio", {make_pair("Oct", 23), make_pair("Nov", 22)}},
	{"Sagittarius", {make_pair("Nov", 23), make_pair("Dec", 21)}},
	{"Aquarius", {make_pair("Jan", 21), make_pair("Feb", 19)}},
	{"Pisces", {make_pair("Feb", 20), make_pair("Mar", 20)}},
});

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int d, f = 0;
		string m;
		cin >> d >> m;
		for (auto const &v : segments)
		{
			int a, b;
			a = comp(d, m, v.second[0].second, v.second[0].first);
			b = comp(d, m, v.second[1].second, v.second[1].first);
			if (a * b <= 0)
			{
				cout << v.first << '\n';
				f = 1;
				break;
			}
		}
		if (!f)
		{
			cout << "Capricorn\n";
		}
	}
	return 0;
}