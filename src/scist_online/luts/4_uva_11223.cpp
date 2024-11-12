#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

char aKey[] =
	{
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'.', ',', '?', '\'', '!', '/', '(', ')', '&', ':', ';', '=', '+', '-', '_', '"', '@'};

std::string mKey[] =
	{
		".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
		"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
		"..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----",
		"..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
		".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...",
		"-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	std::map<std::string, char> morse_to_char;
	for (int i = 0; i < sizeof(aKey) / sizeof(char); i++)
	{
		morse_to_char[mKey[i]] = aKey[i];
	}
	int n;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);
		cout << "Message #" << (i + 1) << '\n';
		int lj = 0;
		for (int j = 0; j < line.size(); j++)
		{
			if (line[j] != ' ')
			{
				continue;
			}
#ifdef DEBUG
			cout << '"' << line.substr(lj, j - lj) << "\"\n";
#endif
			cout << morse_to_char[line.substr(lj, j - lj)];
			if (j + 1 < line.size() && line[j + 1] == ' ')
			{
				cout << ' ';
				j++;
			}
			lj = j + 1;
		}
		// cout << morse_to_char[line.substr(lj, line.size() - lj)];
		cout << '\n';
		if (i != n - 1)
		{
			cout << '\n';
		}
	}

	return 0;
}