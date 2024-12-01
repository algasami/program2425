#include <bits/stdc++.h>

using namespace std;

int read_image(int n, istringstream &stream)
{
	char c;
	stream >> c;
	if (c == '0')
	{
		return 0;
	}
	if (c == '1')
	{
		return n * n;
	}
	// c == '2'
	int np = n >> 1;
	return read_image(np, stream) + read_image(np, stream) + read_image(np, stream) + read_image(np, stream);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	int n;

	cin >> str >> n;

	istringstream iss(str);

	printf("%d\n", read_image(n, iss));

	return 0;
}